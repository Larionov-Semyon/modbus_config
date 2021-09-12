/****************************************************************************
** Meta object code from reading C++ file 'mode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../configWindow/mode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mode_t {
    QByteArrayData data[11];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mode_t qt_meta_stringdata_Mode = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Mode"
QT_MOC_LITERAL(1, 5, 19), // "change_textModeName"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 25), // "on_buttonModeFile_clicked"
QT_MOC_LITERAL(4, 52, 26), // "on_buttonModeImage_clicked"
QT_MOC_LITERAL(5, 79, 23), // "on_textMode_textChanged"
QT_MOC_LITERAL(6, 103, 25), // "on_textModeEN_textChanged"
QT_MOC_LITERAL(7, 129, 25), // "on_textModeOT_textChanged"
QT_MOC_LITERAL(8, 155, 15), // "change_textEdit"
QT_MOC_LITERAL(9, 171, 10), // "QTextEdit*"
QT_MOC_LITERAL(10, 182, 27) // "on_lineModeName_textChanged"

    },
    "Mode\0change_textModeName\0\0"
    "on_buttonModeFile_clicked\0"
    "on_buttonModeImage_clicked\0"
    "on_textMode_textChanged\0"
    "on_textModeEN_textChanged\0"
    "on_textModeOT_textChanged\0change_textEdit\0"
    "QTextEdit*\0on_lineModeName_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Mode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_textModeName(); break;
        case 1: _t->on_buttonModeFile_clicked(); break;
        case 2: _t->on_buttonModeImage_clicked(); break;
        case 3: _t->on_textMode_textChanged(); break;
        case 4: _t->on_textModeEN_textChanged(); break;
        case 5: _t->on_textModeOT_textChanged(); break;
        case 6: _t->change_textEdit((*reinterpret_cast< QTextEdit*(*)>(_a[1]))); break;
        case 7: _t->on_lineModeName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTextEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mode::change_textModeName)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mode::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Mode.data,
    qt_meta_data_Mode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mode.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Mode::change_textModeName()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
