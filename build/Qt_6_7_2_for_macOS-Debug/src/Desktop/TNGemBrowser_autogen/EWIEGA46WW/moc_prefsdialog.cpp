/****************************************************************************
** Meta object code from reading C++ file 'prefsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/Desktop/prefsdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prefsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSPrefsDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPrefsDialogENDCLASS = QtMocHelpers::stringData(
    "PrefsDialog",
    "settingsChanged",
    "",
    "rebuildHistory",
    "reloadPage",
    "clearCache",
    "reloadCache",
    "verifyData",
    "clearHistory",
    "updateHistorySettings",
    "loadStyle",
    "idx",
    "save",
    "reloadSettings"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPrefsDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,
       4,    0,   82,    2, 0x06,    3 /* Public */,
       5,    0,   83,    2, 0x06,    4 /* Public */,
       6,    0,   84,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    2,   88,    2, 0x08,    9 /* Private */,
      10,    1,   93,    2, 0x28,   12 /* Private | MethodCloned */,
      13,    0,   96,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PrefsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSPrefsDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPrefsDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPrefsDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PrefsDialog, std::true_type>,
        // method 'settingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rebuildHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reloadPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearCache'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reloadCache'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verifyData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateHistorySettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadStyle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'loadStyle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'reloadSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PrefsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PrefsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->settingsChanged(); break;
        case 1: _t->rebuildHistory(); break;
        case 2: _t->reloadPage(); break;
        case 3: _t->clearCache(); break;
        case 4: _t->reloadCache(); break;
        case 5: _t->verifyData(); break;
        case 6: _t->clearHistory(); break;
        case 7: _t->updateHistorySettings(); break;
        case 8: _t->loadStyle((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 9: _t->loadStyle((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->reloadSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PrefsDialog::*)();
            if (_t _q_method = &PrefsDialog::settingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrefsDialog::*)();
            if (_t _q_method = &PrefsDialog::rebuildHistory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PrefsDialog::*)();
            if (_t _q_method = &PrefsDialog::reloadPage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PrefsDialog::*)();
            if (_t _q_method = &PrefsDialog::clearCache; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PrefsDialog::*)();
            if (_t _q_method = &PrefsDialog::reloadCache; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *PrefsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrefsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPrefsDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PrefsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PrefsDialog::settingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PrefsDialog::rebuildHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PrefsDialog::reloadPage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PrefsDialog::clearCache()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PrefsDialog::reloadCache()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
