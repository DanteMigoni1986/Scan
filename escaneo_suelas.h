#ifndef ESCANEO_SUELAS_H
#define ESCANEO_SUELAS_H
#include "Captura.h"
#include "calcula_superficie.h"

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Escaneo_suelas;
}

class Escaneo_suelas : public QWidget
{
    Q_OBJECT
    
public:
    explicit Escaneo_suelas(QWidget *parent = 0);
    ~Escaneo_suelas();
    
private slots:
    void on_Procesar_clicked();
    void on_Display_clicked();
    usb_dev_handle* open_dev(void);
    void delay();
    usb_dev_handle* inicializa_usb();
    int Frame_display();
    void Pre_procesa();
    void on_Escanear_clicked();
    void on_pushButton_clicked();
    void on_Resolution_clicked();
    void on_Pre_procesa_clicked();
    void on_Giro_clicked();
    void on_Avance_clicked();
    int on_Stop_clicked();
    void on_lineal_clicked();
    void on_giratorio_clicked();
    void on_Referencia_clicked();
    void on_Visualizar_clicked();
    void on_Acercar_alejar_clicked();
    void on_rapido_clicked();
    void on_Guardar_clicked();
    void on_Fourier_clicked();
    void on_Bezier_patch_clicked();

private:
    Ui::Escaneo_suelas *ui;
    Captura *thread;
    Calcula_superficie *thread2;
    float exposure;
};

#endif // ESCANEO_SUELAS_H
