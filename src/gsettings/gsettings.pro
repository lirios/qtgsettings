TARGET = QtGSettings
MODULE = QtGSettings

QT -= gui
CONFIG += no_keywords link_pkgconfig create_pc create_prl no_install_prl
PKGCONFIG += gio-2.0

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/qtgsettingsglobal.h \
    $$PWD/qgsettings.h

SOURCES += \
    $$PWD/qgsettings.cpp \
    $$PWD/qgvariantutils_p.cpp \
    $$PWD/utils_p.cpp

QMAKE_PKGCONFIG_NAME = Qt5GSettings
QMAKE_PKGCONFIG_DESCRIPTION = Qt bindings to GSettings
QMAKE_PKGCONFIG_VERSION = $$QTGSETTINGS_VERSION
QMAKE_PKGCONFIG_DESTDIR = pkgconfig

load(liri_qt_module)
