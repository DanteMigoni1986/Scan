#include "escaneo_suelas.h"
#include "ui_escaneo_suelas.h"
// Enables this example to work with a device running the
// libusb-win32 PIC Benchmark Firmware.
#define BENCHMARK_DEVICE

//////////////////////////////////////////////////////////////////////////////
// TEST SETUP (User configurable)

// Issues a Set configuration request
#define TEST_SET_CONFIGURATION

// Issues a claim interface request
#define TEST_CLAIM_INTERFACE

// Use the libusb-win32 async transfer functions. see
// transfer_bulk_async() below.
#define TEST_ASYNC

// Attempts one bulk read.
#define TEST_BULK_READ

// Attempts one bulk write.
// #define TEST_BULK_WRITE

//////////////////////////////////////////////////////////////////////////////
// DEVICE SETUP (User configurable)

// Device vendor and product id.
#define MY_VID 0x04D8
#define MY_PID 0x000B

// Device configuration and interface id.
#define MY_CONFIG 1
#define MY_INTF 0

// Device endpoint(s)
#define EP_IN 0x81
#define EP_OUT 0x01

// Device of bytes to transfer.
#define BUF_SIZE 64

//CImg<float> Puntos_z(197,479,1,1,0), Puntos_x(197,479,1,1,0), Puntos_y(197,479,1,1,0);
int fotos, flag=0,num_frame=1,metodo,filtro,tipo_escaneo;
char acum [1];
usb_dev_handle *dev = NULL;
char tmp[10],pasos[3];
//int indice_prim,metodo,filtro;
//CImgList<float> Imagenes;
//CImg<float> suela_vertices;
//CImgList<unsigned int> object_primitives;
//CImgList<unsigned char> object_colors_1;



Escaneo_suelas::Escaneo_suelas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Escaneo_suelas)
{

    ui->setupUi(this);
    qRegisterMetaType<double>("double");
    qRegisterMetaType<vector<double> >("vector<double>");
    thread = new Captura();
    thread2= new Calcula_superficie();
    connect(thread, SIGNAL(envia_vector(vector<double>)), thread2, SLOT(recibe_vector(vector<double>)));
    //ui->progressBar->setValue(0);
}

Escaneo_suelas::~Escaneo_suelas()
{
    delete thread2;
    delete thread;
    delete ui;
}


usb_dev_handle* Escaneo_suelas::open_dev(void)
{
    struct usb_bus *bus;
    struct usb_device *dev;

    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            if (dev->descriptor.idVendor == MY_VID
                    && dev->descriptor.idProduct == MY_PID)
            {
                return usb_open(dev);
            }
        }
    }
    return NULL;
}


void Escaneo_suelas::delay()
{
    int x,y;
    for(x = 0; x < 10; x++)
    {
        for(y = 0; y < 20000; y++)
        {
        }
    }

}



usb_dev_handle* Escaneo_suelas::inicializa_usb()
{

    dev=NULL;
    usb_init();
    usb_find_busses();
    usb_find_devices();


    if (!(dev = open_dev()))
    {
        printf("error al abrir el dispositivo: \n%s\n", usb_strerror());
        return 0;
    }
    else
    {
        printf("Exito we: dispositivo %04X:%04X abierto\n", MY_VID, MY_PID);
    }



    #ifdef TEST_CLAIM_INTERFACE
    if (usb_claim_interface(dev, 0) < 0)
    {
        printf("error claiming interface #%d:\n%s\n", MY_INTF, usb_strerror());
        usb_close(dev);

    }
    else
    {
        printf("success: claim_interface #%d\n", MY_INTF);
    }
    #endif

    return dev;

}


void Escaneo_suelas::on_Procesar_clicked()
{

    metodo=ui->spinBox->value();
    thread2->comienza2(metodo,filtro,tipo_escaneo,0);
}


void Escaneo_suelas::on_Display_clicked()
{
    thread2->comienza2(metodo,filtro,tipo_escaneo,1);
}



void Escaneo_suelas::on_Escanear_clicked()
{
    tipo_escaneo=1;
    thread->comienza(tipo_escaneo,fotos,exposure);
}

void Escaneo_suelas::on_pushButton_clicked()
{
    QString String = ui->lineEdit->text();
    bool ok;
    fotos = String.toInt(&ok, 10);
}


void Escaneo_suelas::on_Resolution_clicked()
{
    char buffer[4];
    int Resolucion=ui->spinBox_2->value();
    itoa (Resolucion,buffer,10);
    for(int i=2;i<6;i++)
    {
        tmp[i]=buffer[i-2];
        pasos[i-2]=buffer[i-2];
    }

}


void Escaneo_suelas::Pre_procesa()

{
    char buffer2[4],strcompleto[69],buffer3[3],string_proc[69],buffer4[3];
    CImg<float> promediada(300,2672,1,1,0);
    float buffer_img=0;
    ui->progressBar->setRange(0,230);

    for (int i=1;i<=159;i++)
    {
        ui->progressBar->setValue(i);
        for(int j=1;j<=fotos;j=j+2)
        {
            sprintf (buffer2,"%d",i);
            sprintf (buffer3, "%d",j);
            sprintf (buffer4, "%d", j+1);
            char *primero = "C:/Users/TOSHIBA/Pictures/Imgs_proyecto/", *segundo = buffer2,*tercero="_",*cuarto=buffer3, *quinto=".jpg", *sexto=buffer4;
            strcpy(strcompleto, primero);
            strcpy(&strcompleto[ strlen(primero) ], segundo);
            strcpy(&strcompleto[ strlen(strcompleto) ], tercero);
            strcpy(&strcompleto[ strlen(strcompleto) ], cuarto);
            strcpy(&strcompleto[ strlen(strcompleto) ], quinto);
            CImg<float> img(strcompleto);         //Cargar imagen deseada*/

            if(j<fotos)
            {
                strcpy(strcompleto, primero);
                strcpy(&strcompleto[ strlen(primero) ], segundo);
                strcpy(&strcompleto[ strlen(strcompleto) ], tercero);
                strcpy(&strcompleto[ strlen(strcompleto) ], sexto);
                strcpy(&strcompleto[ strlen(strcompleto) ], quinto);
                CImg<float> img2(strcompleto);
            }
            CImg<float> img2(strcompleto);

            if(j<fotos)
            {
                img+=img2;
                img+=promediada;
                promediada=img;
            }

            if(j==fotos)
            {
                img+=promediada;
                promediada=img;
            }

            if(j==fotos || (fotos%2==0 && j==fotos-1))
            {
                promediada/=fotos;
            }
            sprintf (buffer2, "%01d", i);
            char *complemento=".jpg",*numero_img=buffer2, *inicio="C:/Users/TOSHIBA/Pictures/Procesadas/";
            strcpy(string_proc, inicio);
            strcpy(&string_proc[ strlen(inicio) ], numero_img);
            strcpy(&string_proc[ strlen(string_proc) ], complemento);
            promediada.save (string_proc);
            promediada.fill(0);
        }
    }
}

void Escaneo_suelas::on_Pre_procesa_clicked()
{
    Pre_procesa();
}

void Escaneo_suelas::on_Giro_clicked()
{
    int giro;
    QString Sentido = ui->lineEdit_2->text();
    bool ok;
    giro = Sentido.toInt(&ok, 10);
    itoa (giro,acum,10);
    tmp[1]=acum[0];

}

void Escaneo_suelas::on_Avance_clicked()
{
    int ret;
    dev=inicializa_usb();
    flag=1;
    //tmp[1]=*acum;
    printf("el tmp contiene %s\n",tmp);


    //while(flag==1)
    //{

        ret = usb_bulk_write(dev, EP_OUT, tmp, sizeof(tmp), 3000);
        usb_clear_halt(dev, EP_OUT);
        delay();
        on_Stop_clicked();
        usb_release_interface(dev,MY_INTF);
        usb_close(dev);

    //}
}

int Escaneo_suelas::on_Stop_clicked()
{
    flag=0;

    delay();
    return flag;
}

void Escaneo_suelas::on_lineal_clicked()
{
    tmp[0]='k';

}

void Escaneo_suelas::on_giratorio_clicked()
{
    tmp[0]='g';
}



void Escaneo_suelas::on_Referencia_clicked()
{
    thread->comienza(3,fotos,exposure);
}

int Escaneo_suelas::Frame_display()
{
    float gain,gamma,Rate=900.0;
    long numero;

    LUCAM_FRAME_FORMAT Formato;
    HANDLE Camara;
    numero= LucamNumCameras();

    if(numero==0)
    {
        QMessageBox::information(0, "Información al usuario",
            "Se ha encontrado una cámara conectada a su equipo\n"
            "pero no es Lumenera.");
    }


    if(numero>=1)
    {
        QMessageBox::information(0, "Información al usuario",
            "Se ha encontrado una cámara Lumenera\n"
            "conectada al equipo");
    }

    CvCapture* capture = cvCaptureFromCAM( 1 );
    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH,3400);
    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT,2672);

    if ( !capture ) {
        fprintf( stderr, "ERROR: capture is NULL \n" );
        getchar();
        return -1;
    }
    // Create a window in which the captured images will be presented
    cvNamedWindow( "Scan preview", CV_WINDOW_NORMAL );
    //CV_WINDOW_NORMAL
    // Show the image captured from the camera in the window and repeat
    while ( 1 )
    {
        if(numero>=1)
        {
            exposure=ui->display_expo->value();
            Camara=LucamCameraOpen(1);
            LucamSetProperty(Camara, LUCAM_PROP_EXPOSURE, exposure, 0);
            LucamSetProperty(Camara, LUCAM_PROP_GAIN, 1.0, 0);
            LucamSetProperty(Camara, LUCAM_PROP_GAMMA, 1.0, 0);
            LucamSetFormat(Camara, &Formato,Rate );
        }
        // Get one frame
        IplImage* frame = cvQueryFrame( capture );
        if ( !frame )
        {
            fprintf( stderr, "ERROR: frame is null...\n" );
            getchar();
            break;
        }
        cvShowImage( "Scan preview", frame );
        // Do not release the frame!
        //If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
        //remove higher bits using AND operator

        if ( (cvWaitKey(10) & 255) == 27 ) break;
    }
    // Release the capture device housekeeping
    cvReleaseCapture( &capture );
    if(numero>=1)
        LucamCameraClose(Camara);
    cvDestroyWindow( "Scan preview" );
    return 0;
}

void Escaneo_suelas::on_Visualizar_clicked()
{
    Frame_display();
}

void Escaneo_suelas::on_Acercar_alejar_clicked()
{
    tmp[0]='d';
}

void Escaneo_suelas::on_rapido_clicked()
{
    tipo_escaneo=2;
    thread->comienza(tipo_escaneo,fotos, exposure);
}

void Escaneo_suelas::on_Guardar_clicked()
{
    QMessageBox::information(0, "Guardar escaneo",
        "Se guardará el escaneo realizado\n");
    thread2->comienza2(metodo,filtro,tipo_escaneo,2);
}

void Escaneo_suelas::on_Fourier_clicked()
{
    filtro=1;
}

void Escaneo_suelas::on_Bezier_patch_clicked()
{
    filtro=2;
}
