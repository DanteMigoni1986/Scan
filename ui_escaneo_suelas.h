/********************************************************************************
** Form generated from reading UI file 'escaneo_suelas.ui'
**
** Created: Tue 2. Oct 18:23:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCANEO_SUELAS_H
#define UI_ESCANEO_SUELAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Escaneo_suelas
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox_2;
    QDial *dial;
    QPushButton *Resolution;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QPushButton *Giro;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QRadioButton *lineal;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QRadioButton *Acercar_alejar;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QRadioButton *giratorio;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QPushButton *Avance;
    QPushButton *Stop;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Procesar;
    QPushButton *Display;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *Escanear;
    QRadioButton *Pre_procesa;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_15;
    QRadioButton *rapido;
    QRadioButton *Referencia;
    QProgressBar *progressBar;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Visualizar;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QSlider *Exposicion;
    QSpinBox *display_expo;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QSlider *gamma;
    QSpinBox *display_gamma;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QSlider *Ganancia;
    QSpinBox *display_ganancia;
    QLabel *label_11;
    QPushButton *Guardar;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_16;
    QRadioButton *Fourier;
    QRadioButton *Bezier_patch;

    void setupUi(QWidget *Escaneo_suelas)
    {
        if (Escaneo_suelas->objectName().isEmpty())
            Escaneo_suelas->setObjectName(QString::fromUtf8("Escaneo_suelas"));
        Escaneo_suelas->resize(763, 604);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 170, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 191, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(106, 212, 159, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 85, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 113, 84, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 212, 191, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Escaneo_suelas->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        Escaneo_suelas->setFont(font);
        Escaneo_suelas->setCursor(QCursor(Qt::OpenHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Pictures/Imgs_proyecto/lasers.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Escaneo_suelas->setWindowIcon(icon);
        groupBox = new QGroupBox(Escaneo_suelas);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 40, 261, 278));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(0, 170, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(0, 255, 191, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(0, 212, 159, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(0, 85, 63, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(0, 113, 84, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(127, 212, 191, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        groupBox->setPalette(palette1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(4000);

        horizontalLayout_2->addWidget(spinBox_2);

        dial = new QDial(groupBox);
        dial->setObjectName(QString::fromUtf8("dial"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush15(QColor(0, 58, 175, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush15);
        QBrush brush16(QColor(7, 89, 255, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush16);
        QBrush brush17(QColor(3, 73, 215, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        QBrush brush18(QColor(0, 29, 87, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush18);
        QBrush brush19(QColor(0, 38, 117, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush20(QColor(127, 156, 215, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush20);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        dial->setPalette(palette2);
        dial->setMaximum(4000);

        horizontalLayout_2->addWidget(dial);

        Resolution = new QPushButton(groupBox);
        Resolution->setObjectName(QString::fromUtf8("Resolution"));

        horizontalLayout_2->addWidget(Resolution);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        label_3->setPalette(palette3);

        horizontalLayout_4->addWidget(label_3);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(2);

        horizontalLayout_4->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_6->addWidget(lineEdit_2);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        Giro = new QPushButton(groupBox);
        Giro->setObjectName(QString::fromUtf8("Giro"));

        horizontalLayout_7->addWidget(Giro);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineal = new QRadioButton(groupBox);
        lineal->setObjectName(QString::fromUtf8("lineal"));

        horizontalLayout_10->addWidget(lineal);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_14->addWidget(label_12);

        Acercar_alejar = new QRadioButton(groupBox);
        Acercar_alejar->setObjectName(QString::fromUtf8("Acercar_alejar"));

        horizontalLayout_14->addWidget(Acercar_alejar);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        giratorio = new QRadioButton(groupBox);
        giratorio->setObjectName(QString::fromUtf8("giratorio"));

        horizontalLayout_9->addWidget(giratorio);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        Avance = new QPushButton(groupBox);
        Avance->setObjectName(QString::fromUtf8("Avance"));

        horizontalLayout_8->addWidget(Avance);

        Stop = new QPushButton(groupBox);
        Stop->setObjectName(QString::fromUtf8("Stop"));

        horizontalLayout_8->addWidget(Stop);


        verticalLayout->addLayout(horizontalLayout_8);

        groupBox_2 = new QGroupBox(Escaneo_suelas);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(440, 200, 281, 71));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 20, 243, 40));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Procesar = new QPushButton(layoutWidget);
        Procesar->setObjectName(QString::fromUtf8("Procesar"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush21(QColor(0, 255, 0, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush21);
        QBrush brush22(QColor(127, 255, 127, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush22);
        QBrush brush23(QColor(63, 255, 63, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        QBrush brush24(QColor(0, 127, 0, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush24);
        QBrush brush25(QColor(0, 170, 0, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Procesar->setPalette(palette4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Pictures/engrane.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Procesar->setIcon(icon1);
        Procesar->setIconSize(QSize(40, 30));

        horizontalLayout->addWidget(Procesar);

        Display = new QPushButton(layoutWidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Pictures/fft4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Display->setIcon(icon2);
        Display->setIconSize(QSize(40, 30));

        horizontalLayout->addWidget(Display);

        groupBox_3 = new QGroupBox(Escaneo_suelas);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(440, 40, 251, 91));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 220, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Escanear = new QRadioButton(layoutWidget1);
        Escanear->setObjectName(QString::fromUtf8("Escanear"));

        horizontalLayout_5->addWidget(Escanear);

        Pre_procesa = new QRadioButton(layoutWidget1);
        Pre_procesa->setObjectName(QString::fromUtf8("Pre_procesa"));

        horizontalLayout_5->addWidget(Pre_procesa);

        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 60, 223, 25));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        rapido = new QRadioButton(layoutWidget2);
        rapido->setObjectName(QString::fromUtf8("rapido"));

        horizontalLayout_15->addWidget(rapido);

        Referencia = new QRadioButton(layoutWidget2);
        Referencia->setObjectName(QString::fromUtf8("Referencia"));

        horizontalLayout_15->addWidget(Referencia);

        progressBar = new QProgressBar(Escaneo_suelas);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(580, 560, 118, 23));
        progressBar->setValue(24);
        groupBox_4 = new QGroupBox(Escaneo_suelas);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(50, 350, 331, 145));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Visualizar = new QPushButton(groupBox_4);
        Visualizar->setObjectName(QString::fromUtf8("Visualizar"));

        verticalLayout_3->addWidget(Visualizar);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        Exposicion = new QSlider(groupBox_4);
        Exposicion->setObjectName(QString::fromUtf8("Exposicion"));
        Exposicion->setMaximum(191);
        Exposicion->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(Exposicion);

        display_expo = new QSpinBox(groupBox_4);
        display_expo->setObjectName(QString::fromUtf8("display_expo"));
        display_expo->setMaximum(191);
        display_expo->setSingleStep(1);

        horizontalLayout_11->addWidget(display_expo);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        gamma = new QSlider(groupBox_4);
        gamma->setObjectName(QString::fromUtf8("gamma"));
        gamma->setMinimum(1);
        gamma->setMaximum(3);
        gamma->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(gamma);

        display_gamma = new QSpinBox(groupBox_4);
        display_gamma->setObjectName(QString::fromUtf8("display_gamma"));
        display_gamma->setMinimum(1);
        display_gamma->setMaximum(3);

        horizontalLayout_12->addWidget(display_gamma);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_13->addWidget(label_10);

        Ganancia = new QSlider(groupBox_4);
        Ganancia->setObjectName(QString::fromUtf8("Ganancia"));
        Ganancia->setMinimum(1);
        Ganancia->setMaximum(23);
        Ganancia->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(Ganancia);

        display_ganancia = new QSpinBox(groupBox_4);
        display_ganancia->setObjectName(QString::fromUtf8("display_ganancia"));
        display_ganancia->setMinimum(1);
        display_ganancia->setMaximum(23);

        horizontalLayout_13->addWidget(display_ganancia);


        verticalLayout_3->addLayout(horizontalLayout_13);

        Visualizar->raise();
        label_11 = new QLabel(Escaneo_suelas);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(580, 540, 121, 16));
        Guardar = new QPushButton(Escaneo_suelas);
        Guardar->setObjectName(QString::fromUtf8("Guardar"));
        Guardar->setGeometry(QRect(440, 280, 101, 23));
        groupBox_5 = new QGroupBox(Escaneo_suelas);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(440, 140, 251, 51));
        layoutWidget3 = new QWidget(groupBox_5);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 20, 168, 21));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        Fourier = new QRadioButton(layoutWidget3);
        Fourier->setObjectName(QString::fromUtf8("Fourier"));

        horizontalLayout_16->addWidget(Fourier);

        Bezier_patch = new QRadioButton(layoutWidget3);
        Bezier_patch->setObjectName(QString::fromUtf8("Bezier_patch"));

        horizontalLayout_16->addWidget(Bezier_patch);


        retranslateUi(Escaneo_suelas);
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(Exposicion, SIGNAL(valueChanged(int)), display_expo, SLOT(setValue(int)));
        QObject::connect(display_expo, SIGNAL(valueChanged(int)), Exposicion, SLOT(setValue(int)));
        QObject::connect(gamma, SIGNAL(valueChanged(int)), display_gamma, SLOT(setValue(int)));
        QObject::connect(display_gamma, SIGNAL(valueChanged(int)), gamma, SLOT(setValue(int)));
        QObject::connect(Ganancia, SIGNAL(valueChanged(int)), display_ganancia, SLOT(setValue(int)));
        QObject::connect(display_ganancia, SIGNAL(valueChanged(int)), Ganancia, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Escaneo_suelas);
    } // setupUi

    void retranslateUi(QWidget *Escaneo_suelas)
    {
        Escaneo_suelas->setWindowTitle(QApplication::translate("Escaneo_suelas", "Escaneo_suelas", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Escaneo_suelas", "Control del motor", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Escaneo_suelas", "Resoluci\303\263n", 0, QApplication::UnicodeUTF8));
        Resolution->setText(QApplication::translate("Escaneo_suelas", "Ok", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Escaneo_suelas", "Im\303\241genes por paso:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Escaneo_suelas", "Ok", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Escaneo_suelas", "Tipo de distribuci\303\263n:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Escaneo_suelas", "Sentido de giro", 0, QApplication::UnicodeUTF8));
        Giro->setText(QApplication::translate("Escaneo_suelas", "Ok", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Escaneo_suelas", "Avance lineal", 0, QApplication::UnicodeUTF8));
        lineal->setText(QString());
        label_12->setText(QApplication::translate("Escaneo_suelas", "Acercar/Alejar objeto", 0, QApplication::UnicodeUTF8));
        Acercar_alejar->setText(QString());
        label_7->setText(QApplication::translate("Escaneo_suelas", "Avance giratorio", 0, QApplication::UnicodeUTF8));
        giratorio->setText(QString());
        label_5->setText(QApplication::translate("Escaneo_suelas", "Dar avance", 0, QApplication::UnicodeUTF8));
        Avance->setText(QApplication::translate("Escaneo_suelas", "Ok", 0, QApplication::UnicodeUTF8));
        Stop->setText(QApplication::translate("Escaneo_suelas", "Detener", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Escaneo_suelas", "Procesamiento", 0, QApplication::UnicodeUTF8));
        Procesar->setText(QApplication::translate("Escaneo_suelas", "Procesar", 0, QApplication::UnicodeUTF8));
        Display->setText(QApplication::translate("Escaneo_suelas", "Desplegar objeto", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Escaneo_suelas", "Captura y pre-procesamiento", 0, QApplication::UnicodeUTF8));
        Escanear->setText(QApplication::translate("Escaneo_suelas", "Escaneo detallado", 0, QApplication::UnicodeUTF8));
        Pre_procesa->setText(QApplication::translate("Escaneo_suelas", "Filtro temporal", 0, QApplication::UnicodeUTF8));
        rapido->setText(QApplication::translate("Escaneo_suelas", "Escaneo r\303\241pido", 0, QApplication::UnicodeUTF8));
        Referencia->setText(QApplication::translate("Escaneo_suelas", "Tomar referencia", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Escaneo_suelas", "Configurar captura", 0, QApplication::UnicodeUTF8));
        Visualizar->setText(QApplication::translate("Escaneo_suelas", "Visualizar captura", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Escaneo_suelas", "Tiempo de exposici\303\263n (ms)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Escaneo_suelas", "Gamma", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Escaneo_suelas", "Ganancia", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Escaneo_suelas", "Porcentaje de progreso", 0, QApplication::UnicodeUTF8));
        Guardar->setText(QApplication::translate("Escaneo_suelas", "Guardar escaneo", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Escaneo_suelas", "Suavizar", 0, QApplication::UnicodeUTF8));
        Fourier->setText(QApplication::translate("Escaneo_suelas", "Fourier", 0, QApplication::UnicodeUTF8));
        Bezier_patch->setText(QApplication::translate("Escaneo_suelas", "Bezier patches", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Escaneo_suelas: public Ui_Escaneo_suelas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCANEO_SUELAS_H
