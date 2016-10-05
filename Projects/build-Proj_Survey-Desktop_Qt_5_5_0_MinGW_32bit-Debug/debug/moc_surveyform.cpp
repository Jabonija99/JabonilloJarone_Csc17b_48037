/****************************************************************************
** Meta object code from reading C++ file 'surveyform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Proj_Survey/surveyform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'surveyform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SurveyForm_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SurveyForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SurveyForm_t qt_meta_stringdata_SurveyForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SurveyForm"
QT_MOC_LITERAL(1, 11, 10), // "txtConfirm"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "enableSubmit"
QT_MOC_LITERAL(4, 36, 10), // "enableLEQ1"
QT_MOC_LITERAL(5, 47, 10), // "enableLEQ2"
QT_MOC_LITERAL(6, 58, 10), // "enableLEQ3"
QT_MOC_LITERAL(7, 69, 10) // "enableLEQ4"

    },
    "SurveyForm\0txtConfirm\0\0enableSubmit\0"
    "enableLEQ1\0enableLEQ2\0enableLEQ3\0"
    "enableLEQ4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SurveyForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       4,    1,   48,    2, 0x08 /* Private */,
       5,    0,   51,    2, 0x08 /* Private */,
       6,    0,   52,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SurveyForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SurveyForm *_t = static_cast<SurveyForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->txtConfirm(); break;
        case 1: _t->enableSubmit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->enableLEQ1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->enableLEQ2(); break;
        case 4: _t->enableLEQ3(); break;
        case 5: _t->enableLEQ4(); break;
        default: ;
        }
    }
}

const QMetaObject SurveyForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SurveyForm.data,
      qt_meta_data_SurveyForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SurveyForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SurveyForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SurveyForm.stringdata0))
        return static_cast<void*>(const_cast< SurveyForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int SurveyForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
