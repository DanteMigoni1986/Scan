#-------------------------------------------------
#
# Project created by QtCreator 2012-05-24T12:45:28
#
#-------------------------------------------------

QT       += core gui

TARGET = Escaneo_suelas
TEMPLATE = app


SOURCES += main.cpp\
        escaneo_suelas.cpp \
    Captura.cpp \
    calcula_superficie.cpp

HEADERS  += escaneo_suelas.h \
    Captura.h \
    calcula_superficie.h

FORMS    += escaneo_suelas.ui

INCLUDEPATH += $$PWD/../../CImg-1.5.0_beta

DEPENDPATH += $$PWD/../../CImg-1.5.0_beta


LIBS += -luser32 -lshell32 -lgdi32

LIBS += -LC:\Users\TOSHIBA\Documents\OpenCV\lib \
-lopencv_core240 \
-lopencv_highgui240 \
-lopencv_imgproc240 \
-lopencv_features2d240 \
-lopencv_calib3d240





INCLUDEPATH += $$PWD/../../../../../OpenCV2.4/opencv/include/opencv
DEPENDPATH += $$PWD/../../../../../OpenCV2.4/opencv/include/opencv

INCLUDEPATH += $$PWD/../../OpenCV/lib
DEPENDPATH += $$PWD/../../OpenCV/lib


LIBS += -L$$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc/ -llibusb


INCLUDEPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc
DEPENDPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc

LIBS += -L$$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc_i64/ -llibusb


INCLUDEPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc_i64
DEPENDPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc_i64

LIBS += -L$$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc_x64/ -llibusb


INCLUDEPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc_x64
DEPENDPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/lib/msvc_x64

INCLUDEPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/include
DEPENDPATH += $$PWD/../../libusb-win32-bin-1.2.6.0/include




LIBS += -L$$PWD/../../LuCamCapture/Lucam/ -llucamapi

INCLUDEPATH += $$PWD/../../LuCamCapture/Lucam
DEPENDPATH += $$PWD/../../LuCamCapture/Lucam


