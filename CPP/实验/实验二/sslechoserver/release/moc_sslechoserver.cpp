/****************************************************************************
** Meta object code from reading C++ file 'sslechoserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../Qt/Qt5.8.0/Examples/Qt-5.8/websockets/sslechoserver/sslechoserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sslechoserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SslEchoServer_t {
    QByteArrayData data[11];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SslEchoServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SslEchoServer_t qt_meta_stringdata_SslEchoServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SslEchoServer"
QT_MOC_LITERAL(1, 14, 15), // "onNewConnection"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "processTextMessage"
QT_MOC_LITERAL(4, 50, 7), // "message"
QT_MOC_LITERAL(5, 58, 20), // "processBinaryMessage"
QT_MOC_LITERAL(6, 79, 18), // "socketDisconnected"
QT_MOC_LITERAL(7, 98, 11), // "onSslErrors"
QT_MOC_LITERAL(8, 110, 16), // "QList<QSslError>"
QT_MOC_LITERAL(9, 127, 6), // "errors"
QT_MOC_LITERAL(10, 134, 21) // "onTextMessageReceived"

    },
    "SslEchoServer\0onNewConnection\0\0"
    "processTextMessage\0message\0"
    "processBinaryMessage\0socketDisconnected\0"
    "onSslErrors\0QList<QSslError>\0errors\0"
    "onTextMessageReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SslEchoServer[] = {

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
       5,    1,   48,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    1,   52,    2, 0x08 /* Private */,
      10,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void SslEchoServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SslEchoServer *_t = static_cast<SslEchoServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->processTextMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->processBinaryMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->socketDisconnected(); break;
        case 4: _t->onSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 5: _t->onTextMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    }
}

const QMetaObject SslEchoServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SslEchoServer.data,
      qt_meta_data_SslEchoServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SslEchoServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SslEchoServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SslEchoServer.stringdata0))
        return static_cast<void*>(const_cast< SslEchoServer*>(this));
    return QObject::qt_metacast(_clname);
}

int SslEchoServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
