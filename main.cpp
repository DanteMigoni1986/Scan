#include <QtGui/QApplication>
#include "escaneo_suelas.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Escaneo_suelas w;
    w.show();
    
    return app.exec();
}
