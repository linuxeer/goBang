/****************************************************************************
** Meta object code from reading C++ file 'goBang.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "goBang.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goBang.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_goBang_t {
    QByteArrayData data[7];
    char stringdata[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_goBang_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_goBang_t qt_meta_stringdata_goBang = {
    {
QT_MOC_LITERAL(0, 0, 6), // "goBang"
QT_MOC_LITERAL(1, 7, 12), // "drapRedChess"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "drapBlackChess"
QT_MOC_LITERAL(4, 36, 1), // "x"
QT_MOC_LITERAL(5, 38, 1), // "y"
QT_MOC_LITERAL(6, 40, 7) // "restart"

    },
    "goBang\0drapRedChess\0\0drapBlackChess\0"
    "x\0y\0restart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_goBang[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    2,   30,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,

       0        // eod
};

void goBang::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        goBang *_t = static_cast<goBang *>(_o);
        switch (_id) {
        case 0: _t->drapRedChess(); break;
        case 1: _t->drapBlackChess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->restart(); break;
        default: ;
        }
    }
}

const QMetaObject goBang::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_goBang.data,
      qt_meta_data_goBang,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *goBang::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *goBang::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_goBang.stringdata))
        return static_cast<void*>(const_cast< goBang*>(this));
    return QWidget::qt_metacast(_clname);
}

int goBang::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
