/****************************************************************************
** Meta object code from reading C++ file 'Captura.h'
**
** Created: Tue 9. Oct 20:37:56 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Captura.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Captura.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Captura[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,    8,    8,    8, 0x0a,
      64,    8,   60,    8, 0x0a,
      84,    8,    8,    8, 0x0a,
     107,   99,   60,    8, 0x0a,
     122,    8,   60,    8, 0x0a,
     135,    8,    8,    8, 0x0a,
     168,    8,  152,    8, 0x0a,
     179,    8,    8,    8, 0x0a,
     187,    8,  152,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Captura[] = {
    "Captura\0\0tiempos\0envia_vector(vector<double>)\0"
    "stopProcess()\0int\0Escaneo_detallado()\0"
    "Set_exposure()\0Renglon\0el_maximo(Mat)\0"
    "Referencia()\0Escaneo_rapido()\0"
    "usb_dev_handle*\0open_dev()\0delay()\0"
    "inicializa_usb()\0"
};

void Captura::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Captura *_t = static_cast<Captura *>(_o);
        switch (_id) {
        case 0: _t->envia_vector((*reinterpret_cast< const vector<double>(*)>(_a[1]))); break;
        case 1: _t->stopProcess(); break;
        case 2: { int _r = _t->Escaneo_detallado();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->Set_exposure(); break;
        case 4: { int _r = _t->el_maximo((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->Referencia();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: _t->Escaneo_rapido(); break;
        case 7: { usb_dev_handle* _r = _t->open_dev();
            if (_a[0]) *reinterpret_cast< usb_dev_handle**>(_a[0]) = _r; }  break;
        case 8: _t->delay(); break;
        case 9: { usb_dev_handle* _r = _t->inicializa_usb();
            if (_a[0]) *reinterpret_cast< usb_dev_handle**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Captura::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Captura::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Captura,
      qt_meta_data_Captura, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Captura::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Captura::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Captura::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Captura))
        return static_cast<void*>(const_cast< Captura*>(this));
    return QThread::qt_metacast(_clname);
}

int Captura::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Captura::envia_vector(const vector<double> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
