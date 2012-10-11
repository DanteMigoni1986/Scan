#include "Captura.h"

// Enables this example to work with a device running the
// libusb-win32 PIC Benchmark Firmware.
#define BENCHMARK_DEVICE

//////////////////////////////////////////////////////////////////////////////
// TEST SETUP (User configurable)

// Issues a Set configuration request
#define SET_CONFIGURATION

// Issues a claim interface request
#define CLAIM_INTERFACE

// Use the libusb-win32 async transfer functions. see
// transfer_bulk_async() below.
#define ASYNC

// Attempts one bulk read.
#define BULK_READ

// Attempts one bulk write.
// #define TEST_BULK_WRITE

//////////////////////////////////////////////////////////////////////////////
// DEVICE SETUP (User configurable)

// Device vendor and product id.
#define VID 0x04D8
#define PID 0x000B

// Device configuration and interface id.
#define CONFIG 1
#define INTF 0

// Device endpoint(s)
#define IN 0x81
#define OUT 0x01

// Device of bytes to transfer.
#define SIZE 64

usb_dev_handle *device = NULL;


Captura::Captura(QObject *parent)
    : QThread(parent)
{
    m_abort = false;
}

Captura::~Captura()
{
    mutex.lock();
    m_abort = true;
    mutex.unlock();

    wait();
}

//![processing the image (start)]
void Captura::comienza(const int &modo_operacion, const int &imagenes, const float &exp)
{
    modo_opera = modo_operacion;
    num_fotos= imagenes;
    exposure=exp;
    m_abort = false;
    start();
}


usb_dev_handle* Captura::open_dev(void)
{
    struct usb_bus *bus;
    struct usb_device *device;

    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (device = bus->devices; device; device = device->next)
        {
            if (device->descriptor.idVendor == VID
                    && device->descriptor.idProduct == PID)
            {
                return usb_open(device);
            }
        }
    }
    return NULL;
}


void Captura::delay()
{
    int x,y;
    for(x = 0; x < 10; x++)
    {
        for(y = 0; y < 20000; y++)
        {
        }
    }
}


usb_dev_handle* Captura::inicializa_usb()
{

    device=NULL;
    usb_init();
    usb_find_busses();
    usb_find_devices();


    if (!(device = open_dev()))
    {
        printf("error al abrir el dispositivo: \n%s\n", usb_strerror());
        return 0;
    }
    else
    {
        printf("Exito we: dispositivo %04X:%04X abierto\n", VID, PID);
    }

    #ifdef CLAIM_INTERFACE
    if (usb_claim_interface(device, 0) < 0)
    {
        printf("error claiming interface #%d:\n%s\n", INTF, usb_strerror());
        usb_close(device);

    }
    else
    {
        printf("success: claim_interface #%d\n", INTF);
    }
    #endif

    return device;

}


int Captura::el_maximo(Mat Renglon){

    int i=0,temp,indice;
    temp=Renglon.at<uchar>(0);

    for( int j = 0; j < Renglon.rows; j++ )
    {
        if(Renglon.at<uchar>(j)>temp)
        {
            temp=Renglon.at<uchar>(j);            //Aquí ubicamos el máximo del renglón que estamos revisando
            indice=j;                   //Guardamos el índice el máximo
        }
    }
    if(temp<50)
    {
        indice=0;
    }
    return indice;
}

void Captura::Set_exposure()
{
    HANDLE Camara;
    Camara=LucamCameraOpen(1);
    LucamSetProperty(Camara, LUCAM_PROP_GAIN, 1.0, 0);
    LucamSetProperty(Camara, LUCAM_PROP_GAMMA, 1.0, 0);
    VideoCapture cap(1); // open the default camera
    cap.set(CV_CAP_PROP_FRAME_WIDTH,1280);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,1024);
    Mat  ROI;
    double Maxval,limite=218.0;
    exposure=30.0;
    //namedWindow("frame",CV_WINDOW_NORMAL);

    if(cap.isOpened())  // check if we succeeded
    {
        for(;;)
        {
            Mat frame;
            cap >> frame; // get a new frame from camera
            //imshow("frame", frame);
            minMaxIdx(frame, 0, &Maxval, 0, 0);
            waitKey(5);

            if(Maxval<limite)
            {
                exposure=exposure+0.1;
                LucamSetProperty(Camara, LUCAM_PROP_EXPOSURE, exposure, 0);
            }
            else if(Maxval>limite)
            {
                exposure=exposure-0.1;
                LucamSetProperty(Camara, LUCAM_PROP_EXPOSURE, exposure, 0);
            }
                else if(Maxval==limite)
                break;
        }
    }
        LucamCameraClose(Camara);
}

int Captura::Referencia()
{
    string cadena="C:/Users/TOSHIBA/Pictures/Imgs_proyecto/";
    string cadena2=".jpg";
    char buffer [10];
    char buffer2 [10];
    string imagen;
    string subindice;
    int num_imagen=1,ubicacion;
    LUCAM_FRAME_FORMAT Formato;
    HANDLE Camara;
    Set_exposure();

    VideoCapture cap(1); // open the default camera
    cap.set(CV_CAP_PROP_FRAME_WIDTH,1280);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,1024);
    if(!cap.isOpened())  // check if we succeeded
            return -1;

        for(int i=1;i<=12;i++)
        {
            Mat frame;
            cap.retrieve(frame);

            if (i>10)
            {

                itoa (num_imagen,buffer,10);
                imagen=buffer;
                for (int j=1;j<=num_fotos;j++)
                {
                    Mat frame;
                    cap.retrieve(frame);
                    if(j==1)
                    {
                        ubicacion=(frame.cols)/2;
                        Mat renglon;
                        renglon=frame(cv::Rect(ubicacion,0,1,1024));
                        max_index=el_maximo(renglon);
                    }
                    cv::Mat ROI;
                    ROI= frame(cv::Rect(0,max_index-150,1280,200));
                    itoa (j,buffer2,10);
                    subindice=buffer2;
                    string cadena3= cadena + "0"+"_"+subindice+cadena2;
                    imwrite(cadena3, ROI);
                }
                num_imagen=num_imagen+1;
            }

            if(waitKey(30) >= 0) break;
        }

        char strcompleto[69],buffer3[3],string_proc[69],buffer4[3];
        CImg<float> promediada(1280,200,1,1,0);
        CImg<float> rotada(200,1280,1,1,0);
        float buffer_img=0;

        for(int j=1;j<=num_fotos;j=j+2)
        {
            sprintf (buffer3, "%01d", j);
            sprintf (buffer4, "%01d", j+1);
            char *primero = "C:/Users/TOSHIBA/Pictures/Imgs_proyecto/", *segundo = "0",*tercero="_",*cuarto=buffer3, *quinto=".jpg", *sexto=buffer4;
            strcpy(strcompleto, primero);
            strcpy(&strcompleto[ strlen(primero) ], segundo);
            strcpy(&strcompleto[ strlen(strcompleto) ], tercero);
            strcpy(&strcompleto[ strlen(strcompleto) ], cuarto);
            strcpy(&strcompleto[ strlen(strcompleto) ], quinto);
            CImg<float> img(strcompleto);         //Cargar imagen deseada

            if(j<num_fotos)
            {
                strcpy(strcompleto, primero);
                strcpy(&strcompleto[ strlen(primero) ], segundo);
                strcpy(&strcompleto[ strlen(strcompleto) ], tercero);
                strcpy(&strcompleto[ strlen(strcompleto) ], sexto);
                strcpy(&strcompleto[ strlen(strcompleto) ], quinto);
                CImg<float> img2(strcompleto);
            }
            CImg<float> img2(strcompleto);

                    if(j<num_fotos)
                    {
                        img+=img2;
                        img+=promediada;
                        promediada=img;
                    }

                    if(j==num_fotos)
                    {
                        img+=promediada;
                        promediada=img;
                    }

                    if(j==num_fotos || (num_fotos%2==0 && j==num_fotos-1))
                    {
                        promediada/=num_fotos;
                    }
        }

        rotada=promediada.rotate(90);

        char *complemento=".jpg",*numero_img="0", *inicio="C:/Users/TOSHIBA/Pictures/Escaneo_rapido/";
        strcpy(string_proc, inicio);
        strcpy(&string_proc[ strlen(inicio) ], numero_img);
        strcpy(&string_proc[ strlen(string_proc) ], complemento);
        rotada.save (string_proc);
        promediada.fill(0);
        rotada.fill(0);
}

void Captura::Escaneo_rapido()
{
    int k,t,ret;
    double tiempo;
    char buffer [10];
    string string1="C:/Users/TOSHIBA/Pictures/Escaneo_rapido/",string2,string_completo;
    usb_dev_handle *dev = NULL; // the device handle
    char tmp[SIZE];
    vector<double>::iterator it;
    vector<double> tiempos;
    //Set_exposure();
    VideoCapture cap(1); // open the default camera
    cap.set(CV_CAP_PROP_FRAME_WIDTH,1280);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,1024);
    Mat frame, ROI;
    CImg<float> rotada(1024,180,1,1,0);

    dev=inicializa_usb();

    tmp[0]='k';
    tmp[1]='1';
    tmp[2]='3';
    tmp[3]='6';
    tmp[4]='0';
    tmp[5]='0';
    ret = usb_bulk_write(dev, OUT, tmp, sizeof(tmp), 50);
    usb_clear_halt(dev,OUT);


    if(cap.isOpened())  // check if we succeeded
    {
        for(int j=1;j<=350;j++)
        {
            k=clock();
            cap >> frame; // get a new frame from camera
            itoa (j,buffer,10);
            string2=buffer;
            ROI= frame(cv::Rect(0,max_index-150,1280,200));
            imwrite(string1 +string2+".jpg", ROI);
            t=clock();
            tiempo= (float)(t-k)/CLOCKS_PER_SEC;
            it = tiempos.end();
            it = tiempos.insert ( it ,tiempo);
        }
    }
    emit envia_vector(tiempos);

    tmp[0]='k';
    tmp[1]='2';
    tmp[2]='3';
    tmp[3]='6';
    tmp[4]='0';
    tmp[5]='0';
    ret = usb_bulk_write(dev, OUT, tmp, sizeof(tmp), 50);
    usb_clear_halt(dev, OUT);
    usb_release_interface(dev,INTF);
    usb_close(dev);
}


int Captura::Escaneo_detallado()
{
    cout<<"Estas en escaneo detallado papirrin";
    cout << endl;
    /*
    usb_dev_handle *dev = NULL;
    char tmp[BUF_SIZE]="d";
    char var[BUF_SIZE];
    int ret,ret2;
    string cadena="C:/Users/TOSHIBA/Pictures/Imgs_proyecto/";
    string cadena2=".jpg";
    char buffer [10];
    char buffer2 [10];
    string imagen;
    string subindice;
    int num_imagen=1;
    dev=inicializa_usb();
    VideoCapture cap(1); // open the default camera
    cap.set(CV_CAP_PROP_FRAME_WIDTH,3400);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,2672);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    ui->progressBar->setRange(0,168);

    for(int i=1;i<169;i++)
    {
        Mat frame;
        cap.retrieve(frame);
        ui->progressBar->setValue(i);

        if (i>=10)
        {
            itoa (num_imagen,buffer,10);
            imagen=buffer;
            for (int j=1;j<=num_fotos;j++)
            {
                Mat frame;
                cap.retrieve(frame);
                cv::Mat ROI;
                ROI= frame(cv::Rect(3030,0,300,2672));
                itoa (j,buffer2,10);
                subindice=buffer2;
                string cadena3= cadena + imagen+"_"+subindice+cadena2;
                imwrite(cadena3, ROI);
            }
            num_imagen=num_imagen+1;
            if (i<211)
            {
                tmp[0]='k';
                tmp[1]='1';
                tmp[2]=pasos[0];
                tmp[3]=pasos[1];
                ret = usb_bulk_write(dev, EP_OUT, tmp, sizeof(tmp), 500);
                usb_clear_halt(dev, EP_OUT);
                delay();*/
          //  }
          /*      if (i==240)
                {
                    for (int g=0;g<18;g++)
                            {
                                tmp[0]='d';
                                tmp[1]='1';
                                tmp[2]='6';
                                tmp[3]='3';
                                ret = usb_bulk_write(dev, EP_OUT, tmp, sizeof(tmp), 300);
                                usb_clear_halt(dev, EP_OUT);
                                for (double t=0;t<1500;t++)
                                    delay();
                            }
                            tmp[0]='g';
                            tmp[1]='1';
                            tmp[2]='1';
                            tmp[3]='0';
                            tmp[4]='0';
                            ret = usb_bulk_write(dev, EP_OUT, tmp, sizeof(tmp), 500);

                            for(double u=1;u<5000;u++)
                                delay();
                            usb_clear_halt(dev, EP_OUT);
                        }

                        if (i>=241 && i<488)
                        {
                            tmp[0]='k';
                            tmp[1]='1';
                            tmp[2]=pasos[0];
                            tmp[3]=pasos[1];
                            ret = usb_bulk_write(dev, EP_OUT, tmp, sizeof(tmp), 500);
                            delay();
                            usb_clear_halt(dev, EP_OUT);
                        }*/

            /*

                    }


                    if(waitKey(30) >= 0) break;
                }
                usb_release_interface(dev,MY_INTF);
                usb_close(dev);*/
                return 0;
}




void Captura::run()
{
    switch(modo_opera)
    {
        case 1:
            Escaneo_detallado();
            break;
        case 2:
            Escaneo_rapido();
            break;
        case 3:
            Referencia();
            break;
        default:
            break;
    }
}


//![processing the image (finish)]

void Captura::stopProcess()
{
    mutex.lock();
    m_abort = true;
    mutex.unlock();
}
