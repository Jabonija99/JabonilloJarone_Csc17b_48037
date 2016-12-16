/****************************************************************************
** Meta object code from reading C++ file 'cart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ShoppingCart2/cart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cart_t {
    QByteArrayData data[13];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cart_t qt_meta_stringdata_Cart = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Cart"
QT_MOC_LITERAL(1, 5, 7), // "toCheck"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 6), // "toShop"
QT_MOC_LITERAL(4, 21, 8), // "toRemove"
QT_MOC_LITERAL(5, 30, 3), // "add"
QT_MOC_LITERAL(6, 34, 5), // "Item*"
QT_MOC_LITERAL(7, 40, 6), // "goNext"
QT_MOC_LITERAL(8, 47, 6), // "goBack"
QT_MOC_LITERAL(9, 54, 7), // "remItem"
QT_MOC_LITERAL(10, 62, 4), // "rem1"
QT_MOC_LITERAL(11, 67, 4), // "rem2"
QT_MOC_LITERAL(12, 72, 4) // "rem3"

    },
    "Cart\0toCheck\0\0toShop\0toRemove\0add\0"
    "Item*\0goNext\0goBack\0remItem\0rem1\0rem2\0"
    "rem3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   69,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cart *_t = static_cast<Cart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toCheck(); break;
        case 1: _t->toShop(); break;
        case 2: _t->toRemove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->add((*reinterpret_cast< Item*(*)>(_a[1]))); break;
        case 4: _t->goNext(); break;
        case 5: _t->goBack(); break;
        case 6: _t->remItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->rem1(); break;
        case 8: _t->rem2(); break;
        case 9: _t->rem3(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cart::toCheck)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Cart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cart::toShop)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Cart::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cart::toRemove)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Cart::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Cart.data,
      qt_meta_data_Cart,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cart::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cart.stringdata0))
        return static_cast<void*>(const_cast< Cart*>(this));
    return QDialog::qt_metacast(_clname);
}

int Cart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Cart::toCheck()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Cart::toShop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Cart::toRemove(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
