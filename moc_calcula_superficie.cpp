/****************************************************************************
** Meta object code from reading C++ file 'calcula_superficie.h'
**
** Created: Tue 9. Oct 20:14:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calcula_superficie.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calcula_superficie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Calcula_superficie[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      34,   19,   19,   19, 0x0a,
      55,   19,   19,   19, 0x0a,
      77,   69,   19,   19, 0x0a,
     119,  111,  107,   19, 0x0a,
     170,  146,  139,   19, 0x0a,
     247,  210,  139,   19, 0x0a,
     316,  300,  288,   19, 0x0a,
     374,  359,  139,   19, 0x0a,
     411,  359,  405,   19, 0x0a,
     449,  438,  288,   19, 0x0a,
     472,  470,  139,   19, 0x0a,
     490,  438,  288,   19, 0x0a,
     549,  518,  288,   19, 0x0a,
     677,  637,  626,   19, 0x0a,
     807,  765,  750,   19, 0x0a,
     871,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Calcula_superficie[] = {
    "Calcula_superficie\0\0stopProcess()\0"
    "Introduce_imagenes()\0Reconstruye()\0"
    "tiempos\0recibe_vector(vector<double>)\0"
    "int\0Renglon\0maximo(CImg<float>)\0double\0"
    "Renglon,indice,solucion\0"
    "derivada_Bezier(CImg<float>,int,double)\0"
    "x_inferior,x_superior,Renglon,indice\0"
    "bisection(double,double,CImg<float>,int)\0"
    "CImg<float>\0matriz1,matriz2\0"
    "Multiplica_matriz(CImg<float>,CImg<float>)\0"
    "Renglon,indice\0Gaussian_dist(CImg<float>,int)\0"
    "float\0centroide(CImg<float>,int)\0"
    "Superficie\0Fourier(CImg<float>)\0n\0"
    "Factorial(double)\0Bezier_patches(CImg<float>)\0"
    "Referencia,ekis,ye,vector,cara\0"
    "Calculo_de_superficie(CImg<float>,CImg<float>&,CImg<float>&,vector<int"
    ">,int)\0"
    "CImg<uint>\0object_vertices,Superficie,ekis,ye,cara\0"
    "Ordenar_puntos(CImgList<float>&,CImg<float>,CImg<float>,CImg<float>,in"
    "t)\0"
    "CImgList<uint>\0Superficie,Puntos_ordenados,object_colors\0"
    "Mesh_algoritmo(CImg<float>,CImg<uint>,CImgList<unsigned char>&)\0"
    "Display_mesh()\0"
};

void Calcula_superficie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Calcula_superficie *_t = static_cast<Calcula_superficie *>(_o);
        switch (_id) {
        case 0: _t->stopProcess(); break;
        case 1: _t->Introduce_imagenes(); break;
        case 2: _t->Reconstruye(); break;
        case 3: _t->recibe_vector((*reinterpret_cast< const vector<double>(*)>(_a[1]))); break;
        case 4: { int _r = _t->maximo((*reinterpret_cast< CImg<float>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { double _r = _t->derivada_Bezier((*reinterpret_cast< CImg<float>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->bisection((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< CImg<float>(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { CImg<float> _r = _t->Multiplica_matriz((*reinterpret_cast< CImg<float>(*)>(_a[1])),(*reinterpret_cast< CImg<float>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< CImg<float>*>(_a[0]) = _r; }  break;
        case 8: { double _r = _t->Gaussian_dist((*reinterpret_cast< CImg<float>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 9: { float _r = _t->centroide((*reinterpret_cast< CImg<float>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 10: { CImg<float> _r = _t->Fourier((*reinterpret_cast< CImg<float>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CImg<float>*>(_a[0]) = _r; }  break;
        case 11: { double _r = _t->Factorial((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 12: { CImg<float> _r = _t->Bezier_patches((*reinterpret_cast< CImg<float>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CImg<float>*>(_a[0]) = _r; }  break;
        case 13: { CImg<float> _r = _t->Calculo_de_superficie((*reinterpret_cast< CImg<float>(*)>(_a[1])),(*reinterpret_cast< CImg<float>(*)>(_a[2])),(*reinterpret_cast< CImg<float>(*)>(_a[3])),(*reinterpret_cast< vector<int>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< CImg<float>*>(_a[0]) = _r; }  break;
        case 14: { CImg<uint> _r = _t->Ordenar_puntos((*reinterpret_cast< CImgList<float>(*)>(_a[1])),(*reinterpret_cast< CImg<float>(*)>(_a[2])),(*reinterpret_cast< CImg<float>(*)>(_a[3])),(*reinterpret_cast< CImg<float>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< CImg<uint>*>(_a[0]) = _r; }  break;
        case 15: { CImgList<uint> _r = _t->Mesh_algoritmo((*reinterpret_cast< CImg<float>(*)>(_a[1])),(*reinterpret_cast< CImg<uint>(*)>(_a[2])),(*reinterpret_cast< CImgList<unsigned char>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< CImgList<uint>*>(_a[0]) = _r; }  break;
        case 16: _t->Display_mesh(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Calcula_superficie::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Calcula_superficie::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Calcula_superficie,
      qt_meta_data_Calcula_superficie, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Calcula_superficie::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Calcula_superficie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Calcula_superficie::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calcula_superficie))
        return static_cast<void*>(const_cast< Calcula_superficie*>(this));
    return QThread::qt_metacast(_clname);
}

int Calcula_superficie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
