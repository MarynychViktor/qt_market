/****************************************************************************
** Meta object code from reading C++ file 'OrderWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../workers/OrderWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OrderWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderWorker_t {
    QByteArrayData data[8];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderWorker_t qt_meta_stringdata_OrderWorker = {
    {
QT_MOC_LITERAL(0, 0, 11), // "OrderWorker"
QT_MOC_LITERAL(1, 12, 7), // "started"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "finished"
QT_MOC_LITERAL(4, 30, 4), // "quit"
QT_MOC_LITERAL(5, 35, 5), // "error"
QT_MOC_LITERAL(6, 41, 3), // "err"
QT_MOC_LITERAL(7, 45, 5) // "start"

    },
    "OrderWorker\0started\0\0finished\0quit\0"
    "error\0err\0start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void OrderWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrderWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->finished(); break;
        case 2: _t->quit(); break;
        case 3: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrderWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderWorker::started)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OrderWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderWorker::finished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OrderWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderWorker::quit)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (OrderWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderWorker::error)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrderWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<Worker::staticMetaObject>(),
    qt_meta_stringdata_OrderWorker.data,
    qt_meta_data_OrderWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OrderWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderWorker.stringdata0))
        return static_cast<void*>(this);
    return Worker::qt_metacast(_clname);
}

int OrderWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void OrderWorker::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void OrderWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void OrderWorker::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void OrderWorker::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
