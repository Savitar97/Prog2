/****************************************************************************
** Meta object code from reading C++ file 'BrainBThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "BrainBThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BrainBThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrainBThread_t {
    QByteArrayData data[13];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrainBThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrainBThread_t qt_meta_stringdata_BrainBThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BrainBThread"
QT_MOC_LITERAL(1, 13, 13), // "heroesChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "image"
QT_MOC_LITERAL(4, 34, 1), // "x"
QT_MOC_LITERAL(5, 36, 1), // "y"
QT_MOC_LITERAL(6, 38, 11), // "endAndStats"
QT_MOC_LITERAL(7, 50, 1), // "t"
QT_MOC_LITERAL(8, 52, 7), // "doStuff"
QT_MOC_LITERAL(9, 60, 8), // "doStuff2"
QT_MOC_LITERAL(10, 69, 13), // "updateCaption"
QT_MOC_LITERAL(11, 83, 10), // "set_color2"
QT_MOC_LITERAL(12, 94, 5) // "setxy"

    },
    "BrainBThread\0heroesChanged\0\0image\0x\0"
    "y\0endAndStats\0t\0doStuff\0doStuff2\0"
    "updateCaption\0set_color2\0setxy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrainBThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       6,    1,   56,    2, 0x06 /* Public */,
       8,    0,   59,    2, 0x06 /* Public */,
       9,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   61,    2, 0x0a /* Public */,
      11,    0,   62,    2, 0x0a /* Public */,
      12,    2,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

       0        // eod
};

void BrainBThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BrainBThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->heroesChanged((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 1: _t->endAndStats((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->doStuff(); break;
        case 3: _t->doStuff2(); break;
        case 4: _t->updateCaption(); break;
        case 5: _t->set_color2(); break;
        case 6: _t->setxy((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BrainBThread::*)(const QImage & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrainBThread::heroesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BrainBThread::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrainBThread::endAndStats)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BrainBThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrainBThread::doStuff)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BrainBThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BrainBThread::doStuff2)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BrainBThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_BrainBThread.data,
    qt_meta_data_BrainBThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BrainBThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrainBThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrainBThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BrainBThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void BrainBThread::heroesChanged(const QImage & _t1, const int & _t2, const int & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BrainBThread::endAndStats(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BrainBThread::doStuff()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BrainBThread::doStuff2()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
