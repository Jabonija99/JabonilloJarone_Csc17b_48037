/****************************************************************************
** Meta object code from reading C++ file 'store.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ShoppingCart2/store.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'store.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Store_t {
    QByteArrayData data[11];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Store_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Store_t qt_meta_stringdata_Store = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Store"
QT_MOC_LITERAL(1, 6, 8), // "sendItem"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "Item*"
QT_MOC_LITERAL(4, 22, 4), // "item"
QT_MOC_LITERAL(5, 27, 6), // "toInfo"
QT_MOC_LITERAL(6, 34, 6), // "toCart"
QT_MOC_LITERAL(7, 41, 9), // "loadItem1"
QT_MOC_LITERAL(8, 51, 9), // "loadItem2"
QT_MOC_LITERAL(9, 61, 9), // "loadItem3"
QT_MOC_LITERAL(10, 71, 6) // "goCart"

    },
    "Store\0sendItem\0\0Item*\0item\0toInfo\0"
    "toCart\0loadItem1\0loadItem2\0loadItem3\0"
    "goCart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Store[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Store::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Store *_t = static_cast<Store *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendItem((*reinterpret_cast< Item*(*)>(_a[1]))); break;
        case 1: _t->toInfo(); break;
        case 2: _t->toCart(); break;
        case 3: _t->loadItem1(); break;
        case 4: _t->loadItem2(); break;
        case 5: _t->loadItem3(); break;
        case 6: _t->goCart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Store::*_t)(Item * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Store::sendItem)) {
                *result = 0;
            }
        }
        {
            typedef void (Store::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Store::toInfo)) {
                *result = 1;
            }
        }
        {
            typedef void (Store::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Store::toCart)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Store::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Store.data,
      qt_meta_data_Store,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Store::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Store::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Store.stringdata0))
        return static_cast<void*>(const_cast< Store*>(this));
    return QDialog::qt_metacast(_clname);
}

int Store::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Store::sendItem(Item * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Store::toInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Store::toCart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
