/****************************************************************************
** Meta object code from reading C++ file 'chatwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Messenger/Client/chatwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatWindow_t {
    QByteArrayData data[25];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatWindow_t qt_meta_stringdata_ChatWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatWindow"
QT_MOC_LITERAL(1, 11, 12), // "attemptLogin"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "userName"
QT_MOC_LITERAL(4, 34, 17), // "attemptConnection"
QT_MOC_LITERAL(5, 52, 17), // "connectedToServer"
QT_MOC_LITERAL(6, 70, 15), // "messageReceived"
QT_MOC_LITERAL(7, 86, 6), // "sender"
QT_MOC_LITERAL(8, 93, 4), // "text"
QT_MOC_LITERAL(9, 98, 4), // "time"
QT_MOC_LITERAL(10, 103, 11), // "sendMessage"
QT_MOC_LITERAL(11, 115, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(12, 138, 20), // "disconnectFromServer"
QT_MOC_LITERAL(13, 159, 10), // "userJoined"
QT_MOC_LITERAL(14, 170, 8), // "userLeft"
QT_MOC_LITERAL(15, 179, 13), // "tryChangeName"
QT_MOC_LITERAL(16, 193, 15), // "userChangedName"
QT_MOC_LITERAL(17, 209, 7), // "oldName"
QT_MOC_LITERAL(18, 217, 7), // "newName"
QT_MOC_LITERAL(19, 225, 10), // "changeName"
QT_MOC_LITERAL(20, 236, 14), // "handlingErrors"
QT_MOC_LITERAL(21, 251, 11), // "errorReason"
QT_MOC_LITERAL(22, 263, 8), // "loggedIn"
QT_MOC_LITERAL(23, 272, 11), // "loginFailed"
QT_MOC_LITERAL(24, 284, 6) // "reason"

    },
    "ChatWindow\0attemptLogin\0\0userName\0"
    "attemptConnection\0connectedToServer\0"
    "messageReceived\0sender\0text\0time\0"
    "sendMessage\0disconnectedFromServer\0"
    "disconnectFromServer\0userJoined\0"
    "userLeft\0tryChangeName\0userChangedName\0"
    "oldName\0newName\0changeName\0handlingErrors\0"
    "errorReason\0loggedIn\0loginFailed\0"
    "reason"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       4,    0,   92,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    3,   94,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,
      13,    1,  104,    2, 0x0a /* Public */,
      14,    1,  107,    2, 0x0a /* Public */,
      15,    0,  110,    2, 0x0a /* Public */,
      16,    2,  111,    2, 0x0a /* Public */,
      19,    1,  116,    2, 0x0a /* Public */,
      20,    1,  119,    2, 0x0a /* Public */,
      22,    0,  122,    2, 0x0a /* Public */,
      23,    1,  123,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

void ChatWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->attemptLogin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->attemptConnection(); break;
        case 2: _t->connectedToServer(); break;
        case 3: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->sendMessage(); break;
        case 5: _t->disconnectedFromServer(); break;
        case 6: _t->disconnectFromServer(); break;
        case 7: _t->userJoined((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->userLeft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->tryChangeName(); break;
        case 10: _t->userChangedName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->changeName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->handlingErrors((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->loggedIn(); break;
        case 14: _t->loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ChatWindow.data,
    qt_meta_data_ChatWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChatWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
