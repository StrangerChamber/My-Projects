/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game_of_Life/gamewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWidget_t {
    QByteArrayData data[18];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWidget"
QT_MOC_LITERAL(1, 11, 18), // "environmentChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 2), // "ok"
QT_MOC_LITERAL(4, 34, 8), // "gameEnds"
QT_MOC_LITERAL(5, 43, 5), // "clear"
QT_MOC_LITERAL(6, 49, 4), // "step"
QT_MOC_LITERAL(7, 54, 9), // "startGame"
QT_MOC_LITERAL(8, 64, 6), // "number"
QT_MOC_LITERAL(9, 71, 8), // "stopGame"
QT_MOC_LITERAL(10, 80, 11), // "masterColor"
QT_MOC_LITERAL(11, 92, 14), // "setMasterColor"
QT_MOC_LITERAL(12, 107, 5), // "color"
QT_MOC_LITERAL(13, 113, 9), // "paintGrid"
QT_MOC_LITERAL(14, 123, 9), // "QPainter&"
QT_MOC_LITERAL(15, 133, 1), // "p"
QT_MOC_LITERAL(16, 135, 8), // "paintUni"
QT_MOC_LITERAL(17, 144, 6) // "newGen"

    },
    "GameWidget\0environmentChanged\0\0ok\0"
    "gameEnds\0clear\0step\0startGame\0number\0"
    "stopGame\0masterColor\0setMasterColor\0"
    "color\0paintGrid\0QPainter&\0p\0paintUni\0"
    "newGen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   80,    2, 0x0a /* Public */,
       6,    0,   81,    2, 0x0a /* Public */,
       7,    1,   82,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x2a /* Public | MethodCloned */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      13,    1,   91,    2, 0x08 /* Private */,
      16,    1,   94,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,

       0        // eod
};

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->environmentChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->gameEnds((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->clear(); break;
        case 3: _t->step(); break;
        case 4: _t->startGame((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->startGame(); break;
        case 6: _t->stopGame(); break;
        case 7: { QColor _r = _t->masterColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setMasterColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 9: _t->paintGrid((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 10: _t->paintUni((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 11: _t->newGen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWidget::environmentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWidget::gameEnds)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GameWidget.data,
    qt_meta_data_GameWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GameWidget::environmentChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameWidget::gameEnds(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
