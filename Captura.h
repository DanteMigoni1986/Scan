#ifndef CAPTURA_H
#define CAPTURA_H
#include <QMutex>
#include <QThread>
#include "lucamapi.h"
#include <lusb0_usb.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "cv.h"
#include "highgui.h"
#include "C:\OpenCV2.4\opencv\include\opencv2\opencv.hpp"
#include <time.h>
#include "winbase.h"
#include <QMessageBox>


using namespace cv;

using namespace std;
#include "CImg.h"

using namespace cimg_library;






//! [Captura class definition]
class Captura : public QThread
{
    Q_OBJECT

public:
    Captura(QObject *parent = 0);
    ~Captura();

    void comienza(const int &modo_operacion, const int &imagenes, const float &exp);

signals:
    void envia_vector(const vector<double> &tiempos);

public slots:
    void stopProcess();
    int Escaneo_detallado();
    void Set_exposure();
    int el_maximo(Mat Renglon);
    int Referencia();
    void Escaneo_rapido();
    usb_dev_handle* open_dev(void);
    void delay();
    usb_dev_handle* inicializa_usb();

protected:
    void run();

private:
    int modo_opera;
    int num_fotos;
    bool m_abort;
    int max_index;
    float exposure;
    Mat m_image;
    QMutex mutex;
};

//qRegisterMetaType<Mat>("Mat");
//! [Captura class definition]
#endif // CAPTURA_H
