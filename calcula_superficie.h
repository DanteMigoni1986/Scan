#ifndef CALCULA_SUPERFICIE_H
#define CALCULA_SUPERFICIE_H
#include <QMutex>
#include <QThread>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
#include "CImg.h"

using namespace cimg_library;


class Calcula_superficie : public QThread
{
    Q_OBJECT
public:
    Calcula_superficie(QObject *parent = 0);
    ~Calcula_superficie();

    void comienza2(const int &el_metodo,const int &el_filtro,const int &tipo_escaneo, const int &despliega);


public slots:
    void stopProcess();
    void Introduce_imagenes();
    void Reconstruye();
    void recibe_vector(const vector<double> &tiempos);
    int maximo(CImg<float> Renglon);
    double derivada_Bezier(CImg<float> Renglon,int indice,double solucion);
    double bisection(double x_inferior, double x_superior, CImg<float> Renglon,int indice );
    CImg <float> Multiplica_matriz(CImg <float> matriz1,CImg <float> matriz2);
    double Gaussian_dist(CImg<float> Renglon,int indice);
    float centroide(CImg<float> Renglon,int indice);
    CImg<float> Fourier(CImg<float> Superficie);
    double Factorial(double n);
    CImg<float> Bezier_patches(CImg<float> Superficie);
    CImg<float> Calculo_de_superficie(CImg<float> Referencia,CImg<float> &ekis,CImg<float> &ye,vector<int> vector,int cara );
    CImg<unsigned int> Ordenar_puntos(CImgList<float> &object_vertices,CImg<float> Superficie,CImg<float> ekis,CImg<float> ye,int cara);
    CImgList<unsigned int> Mesh_algoritmo(CImg<float> Superficie,CImg<unsigned int> Puntos_ordenados,CImgList<unsigned char> &object_colors);
    void Display_mesh();

protected:
    void run();

private:
    bool m_abort;
    QMutex mutex;
    int metodo;
    int filtro;
    int rapido_lento;
    int display;
    int numero_imagenes;

};

#endif // CALCULA_SUPERFICIE_H











