/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_MainWindow_t {};
static constexpr auto qt_meta_stringdata_MainWindow = QtMocHelpers::stringData(
    "MainWindow",
    "on_openButton_released",
    "",
    "on_saveButton_released",
    "on_kakudai_released",
    "on_grayscale_released",
    "on_edge_released",
    "on_filtering_released",
    "on_nitika_released",
    "on_rotate_released",
    "on_srcshow_released",
    "on_clearButton_released",
    "on_toukeiButton_released",
    "on_changeSrcButton_released",
    "on_spinBox_2_valueChanged",
    "arg1"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[20];
    char stringdata5[22];
    char stringdata6[17];
    char stringdata7[22];
    char stringdata8[19];
    char stringdata9[19];
    char stringdata10[20];
    char stringdata11[24];
    char stringdata12[25];
    char stringdata13[28];
    char stringdata14[26];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 22),  // "on_openButton_released"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 22),  // "on_saveButton_released"
        QT_MOC_LITERAL(58, 19),  // "on_kakudai_released"
        QT_MOC_LITERAL(78, 21),  // "on_grayscale_released"
        QT_MOC_LITERAL(100, 16),  // "on_edge_released"
        QT_MOC_LITERAL(117, 21),  // "on_filtering_released"
        QT_MOC_LITERAL(139, 18),  // "on_nitika_released"
        QT_MOC_LITERAL(158, 18),  // "on_rotate_released"
        QT_MOC_LITERAL(177, 19),  // "on_srcshow_released"
        QT_MOC_LITERAL(197, 23),  // "on_clearButton_released"
        QT_MOC_LITERAL(221, 24),  // "on_toukeiButton_released"
        QT_MOC_LITERAL(246, 27),  // "on_changeSrcButton_released"
        QT_MOC_LITERAL(274, 25),  // "on_spinBox_2_valueChanged"
        QT_MOC_LITERAL(300, 4)   // "arg1"
    },
    "MainWindow",
    "on_openButton_released",
    "",
    "on_saveButton_released",
    "on_kakudai_released",
    "on_grayscale_released",
    "on_edge_released",
    "on_filtering_released",
    "on_nitika_released",
    "on_rotate_released",
    "on_srcshow_released",
    "on_clearButton_released",
    "on_toukeiButton_released",
    "on_changeSrcButton_released",
    "on_spinBox_2_valueChanged",
    "arg1"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    0,  100,    2, 0x08,    9 /* Private */,
      11,    0,  101,    2, 0x08,   10 /* Private */,
      12,    0,  102,    2, 0x08,   11 /* Private */,
      13,    0,  103,    2, 0x08,   12 /* Private */,
      14,    1,  104,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_openButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_kakudai_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_grayscale_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_edge_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_filtering_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_nitika_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotate_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_srcshow_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toukeiButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_changeSrcButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_2_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_openButton_released(); break;
        case 1: _t->on_saveButton_released(); break;
        case 2: _t->on_kakudai_released(); break;
        case 3: _t->on_grayscale_released(); break;
        case 4: _t->on_edge_released(); break;
        case 5: _t->on_filtering_released(); break;
        case 6: _t->on_nitika_released(); break;
        case 7: _t->on_rotate_released(); break;
        case 8: _t->on_srcshow_released(); break;
        case 9: _t->on_clearButton_released(); break;
        case 10: _t->on_toukeiButton_released(); break;
        case 11: _t->on_changeSrcButton_released(); break;
        case 12: _t->on_spinBox_2_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
