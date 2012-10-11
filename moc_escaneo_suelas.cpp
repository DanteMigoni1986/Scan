/****************************************************************************
** Meta object code from reading C++ file 'escaneo_suelas.h'
**
** Created: Tue 9. Oct 20:37:50 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../escaneo_suelas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'escaneo_suelas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Escaneo_suelas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      38,   15,   15,   15, 0x08,
      75,   15,   59,   15, 0x08,
      86,   15,   15,   15, 0x08,
      94,   15,   59,   15, 0x08,
     115,   15,  111,   15, 0x08,
     131,   15,   15,   15, 0x08,
     145,   15,   15,   15, 0x08,
     167,   15,   15,   15, 0x08,
     191,   15,   15,   15, 0x08,
     215,   15,   15,   15, 0x08,
     240,   15,   15,   15, 0x08,
     258,   15,   15,   15, 0x08,
     278,   15,  111,   15, 0x08,
     296,   15,   15,   15, 0x08,
     316,   15,   15,   15, 0x08,
     339,   15,   15,   15, 0x08,
     363,   15,   15,   15, 0x08,
     387,   15,   15,   15, 0x08,
     415,   15,   15,   15, 0x08,
     435,   15,   15,   15, 0x08,
     456,   15,   15,   15, 0x08,
     477,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Escaneo_suelas[] = {
    "Escaneo_suelas\0\0on_Procesar_clicked()\0"
    "on_Display_clicked()\0usb_dev_handle*\0"
    "open_dev()\0delay()\0inicializa_usb()\0"
    "int\0Frame_display()\0Pre_procesa()\0"
    "on_Escanear_clicked()\0on_pushButton_clicked()\0"
    "on_Resolution_clicked()\0"
    "on_Pre_procesa_clicked()\0on_Giro_clicked()\0"
    "on_Avance_clicked()\0on_Stop_clicked()\0"
    "on_lineal_clicked()\0on_giratorio_clicked()\0"
    "on_Referencia_clicked()\0on_Visualizar_clicked()\0"
    "on_Acercar_alejar_clicked()\0"
    "on_rapido_clicked()\0on_Guardar_clicked()\0"
    "on_Fourier_clicked()\0on_Bezier_patch_clicked()\0"
};

void Escaneo_suelas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Escaneo_suelas *_t = static_cast<Escaneo_suelas *>(_o);
        switch (_id) {
        case 0: _t->on_Procesar_clicked(); break;
        case 1: _t->on_Display_clicked(); break;
        case 2: { usb_dev_handle* _r = _t->open_dev();
            if (_a[0]) *reinterpret_cast< usb_dev_handle**>(_a[0]) = _r; }  break;
        case 3: _t->delay(); break;
        case 4: { usb_dev_handle* _r = _t->inicializa_usb();
            if (_a[0]) *reinterpret_cast< usb_dev_handle**>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->Frame_display();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: _t->Pre_procesa(); break;
        case 7: _t->on_Escanear_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_Resolution_clicked(); break;
        case 10: _t->on_Pre_procesa_clicked(); break;
        case 11: _t->on_Giro_clicked(); break;
        case 12: _t->on_Avance_clicked(); break;
        case 13: { int _r = _t->on_Stop_clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: _t->on_lineal_clicked(); break;
        case 15: _t->on_giratorio_clicked(); break;
        case 16: _t->on_Referencia_clicked(); break;
        case 17: _t->on_Visualizar_clicked(); break;
        case 18: _t->on_Acercar_alejar_clicked(); break;
        case 19: _t->on_rapido_clicked(); break;
        case 20: _t->on_Guardar_clicked(); break;
        case 21: _t->on_Fourier_clicked(); break;
        case 22: _t->on_Bezier_patch_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Escaneo_suelas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Escaneo_suelas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Escaneo_suelas,
      qt_meta_data_Escaneo_suelas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Escaneo_suelas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Escaneo_suelas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Escaneo_suelas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Escaneo_suelas))
        return static_cast<void*>(const_cast< Escaneo_suelas*>(this));
    return QWidget::qt_metacast(_clname);
}

int Escaneo_suelas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
