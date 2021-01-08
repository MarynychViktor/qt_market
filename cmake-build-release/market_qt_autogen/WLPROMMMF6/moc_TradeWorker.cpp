/****************************************************************************
** Meta object code from reading C++ file 'TradeWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../workers/TradeWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TradeWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TradeWorker_t {
    QByteArrayData data[11];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TradeWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TradeWorker_t qt_meta_stringdata_TradeWorker = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TradeWorker"
QT_MOC_LITERAL(1, 12, 13), // "tradesChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "QList<QString>"
QT_MOC_LITERAL(4, 42, 8), // "tradeIds"
QT_MOC_LITERAL(5, 51, 7), // "started"
QT_MOC_LITERAL(6, 59, 8), // "finished"
QT_MOC_LITERAL(7, 68, 4), // "quit"
QT_MOC_LITERAL(8, 73, 5), // "error"
QT_MOC_LITERAL(9, 79, 3), // "err"
QT_MOC_LITERAL(10, 83, 5) // "start"

    },
    "TradeWorker\0tradesChanged\0\0QList<QString>\0"
    "tradeIds\0started\0finished\0quit\0error\0"
    "err\0start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TradeWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,
       8,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void TradeWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TradeWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tradesChanged((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 1: _t->started(); break;
        case 2: _t->finished(); break;
        case 3: _t->quit(); break;
        case 4: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TradeWorker::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TradeWorker::tradesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TradeWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TradeWorker::started)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TradeWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TradeWorker::finished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TradeWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TradeWorker::quit)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TradeWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TradeWorker::error)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TradeWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<Worker::staticMetaObject>(),
    qt_meta_stringdata_TradeWorker.data,
    qt_meta_data_TradeWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TradeWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TradeWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TradeWorker.stringdata0))
        return static_cast<void*>(this);
    return Worker::qt_metacast(_clname);
}

int TradeWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TradeWorker::tradesChanged(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TradeWorker::started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TradeWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TradeWorker::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TradeWorker::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
