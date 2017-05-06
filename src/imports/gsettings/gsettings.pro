TARGET = qtgsettingsplugin
TARGETPATH = QtGSettings
IMPORT_VERSION = 1.0

QT += qml quick Qt5GSettings

CONFIG += no_keywords

HEADERS += \
    $$PWD/qmlgsettings.h \
    $$PWD/qmlgsettingsschema.h

SOURCES += \
    $$PWD/plugin.cpp \
    $$PWD/qmlgsettings.cpp \
    $$PWD/qmlgsettingsschema.cpp

OTHER_FILES += \
    qmldir

CONFIG += no_cxx_module
load(liri_qml_plugin)
