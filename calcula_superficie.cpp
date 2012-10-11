#include "calcula_superficie.h"
vector<double> delays;
int indice_prim;
CImgList<float> Imagenes;
CImg<float> suela_vertices;
CImgList<unsigned int> object_primitives;
CImgList<unsigned char> object_colors_1;

Calcula_superficie::Calcula_superficie(QObject *parent)
    : QThread(parent)
{
    m_abort = false;
}


Calcula_superficie::~Calcula_superficie()
{
    mutex.lock();
    m_abort = true;
    mutex.unlock();
    wait();
}


void Calcula_superficie::comienza2(const int &el_metodo, const int &el_filtro, const int &tipo_escaneo, const int &despliega)
{
    metodo = el_metodo;
    filtro= el_filtro;
    rapido_lento= tipo_escaneo;
    display=despliega;
    m_abort = false;
    start();
}

void Calcula_superficie::Introduce_imagenes()
{
    char buffer2[4],strcompleto[69];
    int maximo;
    CImg<float> rotated(200,1280,1,1,0);

    if(Imagenes.size()<1)
    {
        for(int i=1;i<350;i++)
        {
            //concatenar un char
            sprintf (buffer2, "%01d", i);
            char *primero = "C:/Users/TOSHIBA/Pictures/Escaneo_rapido/", *segundo = buffer2, *tercero=".jpg";
            strcpy(strcompleto, primero);
            strcpy(&strcompleto[ strlen(primero) ], segundo);
            strcpy(&strcompleto[ strlen(strcompleto) ], tercero);
            //fin de concatenar char
            CImg<float> img(strcompleto);       //Cargar imagen deseada
            maximo=img.max();
            if(maximo>50)
            {
                rotated=img.rotate(90.0);
                Imagenes.insert(rotated,i-1);
            }
        }
    }
    numero_imagenes=Imagenes.size();
}


int Calcula_superficie::maximo(CImg<float> Renglon){

    int i=0,temp,indice;
    temp=Renglon(0);
    for( int j = 0; j < Renglon.width(); j++ )
    {
        if(Renglon(j)>temp)
        {
            temp=Renglon(j);            //Aquí ubicamos el máximo del renglón que estamos revisando
            indice=j;                   //Guardamos el índice el máximo
        }
    }
    if(temp<50)
    {
        indice=0;
    }
    return indice;
}
// fin de ubicar el maximo

double Calcula_superficie::derivada_Bezier(CImg<float> Renglon,int indice,double solucion)
{

    double n=40;
    float inc=(float)1/n;
    float incre=0;
    double derivada_Int,M=20, index=(double)indice,uno=1.0;
    double factorial1,factorial2,factorial3,ayuda,auxiliar1,auxiliar2,permuta;
    ayuda=(double)1;


    for (double h=1;h<=(n-1);h++)
    {
        factorial1=h*ayuda;
        ayuda=factorial1;
    }

    derivada_Int=0;
    for (double i=0;i<=(n-1);i++)
    {
        if (i>=1)
        {
            auxiliar1=1;
            for (double t=1;t<=i;t++)
            {
                factorial2=auxiliar1*t;
                auxiliar1=factorial2;
            }
        }
        else
        {
            factorial2=1;
        }

        if((n-1-i)>=1)
        {
            auxiliar2=1;
            for (double t=1;t<=(n-1-i);t++)
            {
                factorial3=auxiliar2*t;
                auxiliar2=factorial3;
            }
        }
        else
        {
            factorial3=1;
        }

        permuta=factorial1/(factorial2*factorial3);

        derivada_Int=derivada_Int+permuta*(pow(solucion,i))*(pow((uno-solucion),(n-uno-i)))*n*(Renglon((index-M)+i+uno)-Renglon((index-M)+i));
    }
    return derivada_Int;
}


double Calcula_superficie::bisection(double x_inferior, double x_superior, CImg<float> Renglon,int indice )
{
    double result = 0.0,margen=0.001; //el valor propuesto para encontrar el máximo
    double f_result = 1.0; //valor de la derivada de la funcion de Bezier
    int iteration = 0, maxIteration=20;
    double index=(double)indice,derivada_inferior,derivada_superior;
    CImg<float> Renglon1=Renglon;


    while((fabs(f_result)>margen) && (iteration<maxIteration))
    {
        iteration++;
        result= (x_inferior+x_superior)/2;
        f_result = derivada_Bezier(Renglon1,indice,result);

        if (f_result>0)
            x_inferior=result;
        else if(f_result<0)
            x_superior=result;
    }
    result=(result*(double)40)+(index-20);
    return result;
}



CImg <float> Calcula_superficie::Multiplica_matriz(CImg <float> matriz1,CImg <float> matriz2)
{
    double temp;
    int index_ver;
    CImg <float> Resultante (matriz2.width(),matriz2.height(),1,1,0);

    for(int j=0;j<matriz1.height();j++)
    {
        index_ver=0;
        temp=0;
        for(int i=0;i<matriz1.width();i++)
        {
            index_ver=i;
            Resultante(j)= temp+matriz1(i,j)*matriz2(index_ver);
            temp=Resultante(j);
        }
    }
    return Resultante;
}


double Calcula_superficie::Gaussian_dist(CImg<float> Renglon,int indice)
{
    double Em=0, eps_cuadrado=0, eps_cuarta=0, suma_intensidades=0, intensidades_indices=0, intensidades_indices_sq=0,N=30,index=(double)indice;

    for (double posicion=(-N/((double)2));posicion<=(N/((double)2));posicion++)
    {
        eps_cuadrado= eps_cuadrado + pow(posicion,(double)2);
        eps_cuarta= eps_cuarta + pow(posicion,(double)4);
        suma_intensidades= Renglon(index+posicion) + suma_intensidades;
        intensidades_indices= posicion* Renglon(index + posicion) + intensidades_indices;
        intensidades_indices_sq= pow(posicion,(double)2)* Renglon(index+posicion) + intensidades_indices_sq;
    }

    CImg<float> A = CImg<float>(3,3,1,1,  // Define the 8 vertices of the cube.
                                            (N+(double)1),(double)0,eps_cuadrado,
                                            (double)0,eps_cuadrado,(double)0,
                                            eps_cuadrado,(double)0,eps_cuarta // (x0,y0,z0)
                                            );
    A=A.invert(true);
    CImg<float> matriz_aux = CImg<float>(1,3,1,1,  // Define the 8 vertices of the cube.
                                            suma_intensidades,
                                            intensidades_indices,
                                            intensidades_indices_sq // (x0,y0,z0)
                                            );
    CImg<float> Constantes (1,3,1,1,0);
    Constantes= Multiplica_matriz(A,matriz_aux);
    Em=-Constantes(0,1)/((double)2*Constantes(0,2));
    Em=index+Em;

    return Em;
}


float Calcula_superficie::centroide(CImg<float> Renglon,int indice)
{
    float centroide=0,intensidad=0,Centroide1;
    int M=20;

    for (int i=-M;i<=M;i++)
    {
        centroide= centroide+(indice+i)*Renglon(indice+i);
        intensidad= intensidad+Renglon(indice+i);
    }
    Centroide1= centroide/intensidad;
    centroide=0;
    intensidad=0;
    return Centroide1;
}


CImg<float> Calcula_superficie::Fourier(CImg<float> Superficie)
{
    //const CImg<float> img(strcompleto);

    CImg<float>img = Superficie.resize(512,2048);
    CImgList<float> F = img.get_FFT();
    cimglist_apply(F,shift)(img.width()/2,img.height()/2,0,0,2);

    //Creamos un filtro pasabajas Butterworth
    double u= img.height(),v=img.width(),D;
    CImg<float> mask(v,u,1,1,0);
    for(double y=0;y<u;y++)
    {
        for(double x=0;x<v;x++)
        {
            D = sqrt(pow((x-v/2),2) + pow((y-u/2),2));

            mask(x,y) = 1.0/(1.0 + pow((D/100),(2*2)));
        }
    }//fin del filtro pasabajas

    CImgList<float> nF(F);
    cimglist_for(F,l) nF[l].mul(mask).shift(-img.width()/2,-img.height()/2,0,0,2);
    CImg<float> filtrada= nF.FFT(true)[0];
    filtrada.resize(numero_imagenes,1280);

    return filtrada;
}

double Calcula_superficie::Factorial(double n)
{
    double factorial,auxiliar;

    if (n>=1)
    {
        auxiliar=1;
        for (double t=1;t<=n;t++)
        {
            factorial=auxiliar*t;
            auxiliar=factorial;
        }
    }
    else
        {factorial=1;}

    return factorial;
}


CImg<float> Calcula_superficie::Bezier_patches(CImg<float> Superficie)
{
    double n=9, incrementa=0.0, inc=(double)1/n, factorial1, factorial2, factorial4, factorial3, factorial5, var_u,var_v,Intensity_tot;   // checar resultado en un programa aparte
    double permuta_v, permuta_u, Intensity_u, Intensity_v;
    int index_u,index_v;
    vector<float>::iterator it;
    vector<float> incrementos;
    CImg<float> Superficie_bezier(Superficie.width(),Superficie.height(),1,1,0);


    for(double j=1;j<=(n+1);j++)
    {
        it = incrementos.end();
        it = incrementos.insert ( it ,incrementa );
        incrementa=incrementa+inc;
    }

    factorial1=Factorial(n);

    for (double hor=0;hor<=Superficie.width()-n;hor=hor+n)
    {
        for(double vert=0;vert<=Superficie.height()-n;vert=vert+n)
        {
            index_u=0;
            for (int u=0;u<incrementos.size();u++)
            {
                var_u=incrementos[u];
                index_v=0;
                for (int v=0;v<incrementos.size();v++)
                {
                    var_v=incrementos[v];
                    Intensity_tot=0;

                    for (double i=0;i<=n;i++)
                    {
                        for (double j=0;j<=n;j++)
                        {
                            factorial2=Factorial(j);
                            factorial4=Factorial(i);
                            factorial3=Factorial(n-j);
                            factorial5=Factorial(n-i);
                            permuta_v=factorial1/(factorial2*factorial3);
                            permuta_u=factorial1/(factorial4*factorial5);
                            Intensity_v=permuta_v*pow((1-var_v),(n-j))*pow(var_v,j);
                            Intensity_u=permuta_u*pow((1-var_u),(n-i))*pow(var_u,i);
                            Intensity_tot=Intensity_tot+Intensity_v*Intensity_u*Superficie(hor+i,vert+j);
                        }
                    }
                    Superficie_bezier(hor+index_u,vert+index_v)=Intensity_tot;
                    index_v=index_v+1;
                }
                index_u=index_u+1;
            }
        }
    }
    return Superficie_bezier;
}

CImg<float> Calcula_superficie::Calculo_de_superficie(CImg<float> Referencia,CImg<float> &ekis,CImg<float> &ye,vector<int> vector,int cara)
{
    int a,aux,num_imagen,indice_surf=0,resultado;
    int cont=0,bandera=0,bandera2=0,n=0,m=0,i=0,indice_delays=0;
    double columnas=0,filas=0,inicial=0,final=1,velocidad=1.04707125;
    float x=0,y=0;
    CImg<float> Renglon(200,1,1,1,0);
    CImg<float> Delta_x(1280,1,1,1,0);
    CImg<float> Delta_z(1280,1,1,1,0);
    CImg<float> Deformada(1280,1,1,1,0);
    CImg<float> Pixeles(1280,1,1,1,0);
    CImg<float> Superficie(numero_imagenes,1280,1,1,0);

    for (CImgList<float>::iterator it = Imagenes.begin(); it<Imagenes.end(); ++it)
    {
        CImg<float> imagen=*it;

        // fin de recortar la imagen
        for(int j=0;j<1280;j++)
        {
            for(int h=0;h<Renglon.width();h++)
            {
                Renglon(h)=imagen(h,j);

            }
            indice_surf=maximo(Renglon);


            if(indice_surf==0)
            {
                Superficie(i-1,j)= 0;
                ekis(i-1,j)= x;
                ye(i-1,j)= y;

            }
            if(indice_surf>0)
            {
                if (metodo==0)
                    Deformada(j)=centroide(Renglon,indice_surf);
                else if (metodo==1)
                    Deformada(j)=bisection(inicial, final, Renglon,indice_surf );
                else if (metodo==2)
                    Deformada(j)=Gaussian_dist(Renglon,indice_surf);
                Pixeles(j)=Deformada(j)-Referencia(j);
                Delta_x(j)= Pixeles(j)*0.008;
                if(cara==1)
                    Superficie(i-1,j)= (39*Delta_x(j)/(17.5+Delta_x(j)))+4.0;
                if(cara==2)
                    Superficie(i-1,j)= -(39*Delta_x(j)/(17.5+Delta_x(j)))+4.0;
                cont=cont+1;
                ekis(i-1,j)=x;
                ye(i-1,j)=y;
            }
            y=y+0.008;
        }
        y=0;
        if (rapido_lento==1)
            {x=x+0.05000625;}
        else if (rapido_lento==2)
            x=x+delays[indice_delays]*velocidad;
        i++;
        indice_delays++;
    }

 //******************************************************************************************************************

    if (filtro==1)
    {
       Superficie=Fourier(Superficie);
       for (int i=0;i<Superficie.width();i++)
       {
           for(int j=0;j<Superficie.height();j++)
           {
               if(Superficie(i,j)<3.5)
                Superficie(i,j)=0.0;
           }
       }
    }
    if (filtro==2)
    {
        Superficie=Bezier_patches(Superficie);
        for (int i=0;i<Superficie.width();i++)
       {
           for(int j=0;j<Superficie.height();j++)
           {
               if(Superficie(i,j)<3.5)
                Superficie(i,j)=0.0;
           }
       }
    }

    return Superficie;
}



CImg<unsigned int> Calcula_superficie::Ordenar_puntos(CImgList<float> &object_vertices,CImg<float> Superficie,CImg<float> ekis,CImg<float> ye,int cara)
{
    int na=Superficie.width(),nb=Superficie.height();
    CImg<unsigned int> Puntos_ordenados(na,nb,1,1,900000);

    for (int j=0;j<nb;j++)
    {
        for(int i=0;i<na;i++)
        {
            if(Superficie(i,j)>0)
            {
                object_vertices.insert(CImg<float>::vector(ekis(i,j),ye(i,j),Superficie(i,j)));
                Puntos_ordenados(i,j)=indice_prim;
                //printf("%d         ",indice_prim);
                indice_prim++;
            }
        }
    }
    return Puntos_ordenados;
}


CImgList<unsigned int> Calcula_superficie::Mesh_algoritmo(CImg<float> Superficie,CImg<unsigned int> Puntos_ordenados,CImgList<unsigned char> &object_colors)
{
    int limite_hor,limite_ver;
    CImgList<unsigned int> superficie_primitives;
    int na=Superficie.width(),nb=Superficie.height();
    // Construimos el mesh de la superficie obtenida
    unsigned int Primer_punto=0,Segundo_punto=0,Tercer_punto=0,Cuarto_punto=0;
    float color1,color2,color3,color4,maxi;
    int conteo=1,flag1=0,flag2=0,flag3=0,color_total;
    maxi=Superficie.max();

    for (int j=0;j<nb;j++)
    {
        for(int i=0;i<na;i++)
        {
            if(Puntos_ordenados(i,j)<900000)
            {
                Primer_punto=Puntos_ordenados(i,j);
                color1=Superficie(i,j);
                if(Puntos_ordenados(i,j+1)<900000)
                {
                    conteo++;
                    Segundo_punto=Puntos_ordenados(i,j+1);
                    color2=Superficie(i,j+1);
                    flag1=1;
                }
                if(Puntos_ordenados(i+1,j+1)<900000)
                {
                    conteo++;
                    Tercer_punto=Puntos_ordenados(i+1,j+1);
                    color3=Superficie(i+1,j+1);
                    flag2=1;
                }
                if(Puntos_ordenados(i+1,j)<900000)
                {
                    conteo++;
                    Cuarto_punto=Puntos_ordenados(i+1,j);
                    color4=Superficie(i+1,j);
                    flag3=1;
                }
                if(conteo==3)
                {
                    if (flag1==1 && flag2==1)
                    {
                            superficie_primitives.insert(CImg<unsigned int>::vector(Primer_punto,Segundo_punto,Tercer_punto));
                            color_total=int(((color1+color2+color3)*255)/maxi);
                            object_colors.insert(CImg<char>::vector(color_total,50,25));

                    }
                    if(flag1==1 && flag3==1)
                    {
                            superficie_primitives.insert(CImg<unsigned int>::vector(Primer_punto,Segundo_punto,Cuarto_punto));
                            color_total=int(((color1+color2+color4)*255)/maxi);
                            object_colors.insert(CImg<char>::vector(color_total,50,25));
                    }
                    if(flag2==1 && flag3==1)
                    {
                            superficie_primitives.insert(CImg<unsigned int>::vector(Primer_punto,Tercer_punto,Cuarto_punto));
                            color_total=int(((color1+color3+color4)*255)/maxi);
                            object_colors.insert(CImg<char>::vector(color_total,50,25));
                    }
                }
                if(conteo==4)
                {
                        superficie_primitives.insert(CImg<unsigned int>::vector(Primer_punto,Segundo_punto,Tercer_punto,Cuarto_punto));
                        color_total=int(((color1+color2+color3+color4)*255)/maxi);
                        object_colors.insert(CImg<char>::vector(color_total,50,25));
                }
                conteo=1;
                flag1=0;
                flag2=0;
                flag3=0;
            }
        }
    }
    return superficie_primitives;
}

void Calcula_superficie::Reconstruye()
{
    int indice2,itera=0;
    double inicial=0,final=1;
    indice_prim=0;
    CImg<float> Referencia(1280,1,1,1,0);
    CImg<float> Renglon(200,1,1,1,0);
    Introduce_imagenes();
    Imagenes.display();
    CImg<float> Superficie_superior(numero_imagenes,1280,1,1,0);
    CImg<float> Superficie_inferior(numero_imagenes,1280,1,1,0);
    CImg<float> ekis_superior(numero_imagenes,1280,1,1,0);
    CImg<float> ekis_inferior(numero_imagenes,1280,1,1,0);
    CImg<float> ye_superior(numero_imagenes,1280,1,1,0);
    CImg<float> ye_inferior(numero_imagenes,1280,1,1,0);
    vector<int> vector_cara_superior;
    vector<int> vector_cara_inferior;
    vector<int>::iterator it;
    CImgList<float> object_vertices_1;
    CImgList<float> object_vertices_2;
    CImg<unsigned int> Puntos_ordenados_superior;
    CImg<unsigned int> Puntos_ordenados_inferior;
    CImgList<unsigned int> suela_superior;
    CImgList<unsigned int> suela_inferior;
    CImgList<unsigned char> object_colors_2;
    CImgList<unsigned char> colores;
    CImgList<unsigned int> Despliega;
    CImg<unsigned int> Punto;

    for(int j=1;j<160;j++)
    {
        it = vector_cara_superior.end();
        it = vector_cara_superior.insert ( it ,j );
    }

    for(int j=282;j<472;j++)
    {
        it = vector_cara_inferior.end();
        it = vector_cara_inferior.insert ( it ,j );
    }

    // Tomamos la línea de referencia

    const CImg<float> img("C:/Users/TOSHIBA/Pictures/Escaneo_rapido/0.jpg");
    //CImg<float> img2= img.get_crop(0,99,179,2569);

    for(int i=0;i<1280;i++)//2471
    {
        for(int h=0;h<Renglon.width();h++)
        {
            Renglon(h)=img(h,i);
        }

        indice2=maximo(Renglon);
        if (metodo==0)
            Referencia(i)=centroide(Renglon,indice2);
        else if (metodo==1)
            Referencia(i)=bisection(inicial, final, Renglon,indice2);
        else if (metodo==2)
            Referencia(i)=Gaussian_dist(Renglon,indice2);
    }

    Superficie_superior=Calculo_de_superficie(Referencia,ekis_superior,ye_superior,vector_cara_superior,1);
    //Superficie_inferior=Calculo_de_superficie(Referencia,ekis_inferior,ye_inferior,vector_cara_inferior,2);Superficie_inferior.display();
    Puntos_ordenados_superior=Ordenar_puntos(object_vertices_1,Superficie_superior,ekis_superior,ye_superior,1);
    //Puntos_ordenados_inferior=Ordenar_puntos(object_vertices_2,Superficie_inferior,ekis_inferior,ye_inferior,2);
    suela_superior=Mesh_algoritmo(Superficie_superior,Puntos_ordenados_superior,object_colors_1);
    //suela_inferior=Mesh_algoritmo(Superficie_inferior,Puntos_ordenados_inferior,object_colors_2);
    /* object_colors_1.push_back(object_colors_2);  //tienes q comentar estos si solo quieres mostrar una cara
    object_vertices_1.push_back(object_vertices_2);//tienes q comentar estos si solo quieres mostrar una cara
    suela_superior.push_back(suela_inferior);*///tienes q comentar estos si solo quieres mostrar una cara
    suela_vertices.append_object3d(object_primitives,object_vertices_1>'x',suela_superior);
}

void Calcula_superficie::Display_mesh()
{
    CImgDisplay disp(800,600,"Object Display",0);
    CImg<unsigned char>(disp.width(),disp.height(),1,3,220).display_object3d(disp,suela_vertices,object_primitives,object_colors_1,true,4,3,false,500,0,0,-5000,0.0f,0.0f,true);

}

void Calcula_superficie::run()
{
    switch(display)
    {
        case 0:
            Reconstruye();
            break;
        case 1:
            Display_mesh();
            break;
        case 2:
            suela_vertices.save_off("plantilla_peque.off",object_primitives,object_colors_1);
        default:
            break;
    }
}


void Calcula_superficie::recibe_vector(const vector<double> &tiempos)
{
    delays=tiempos;
    for (int i=0; i < delays.size(); i++)
        cout << " " << delays[i];

      cout << endl;    
}

void Calcula_superficie::stopProcess()
{
    mutex.lock();
    m_abort = true;
    mutex.unlock();
}
