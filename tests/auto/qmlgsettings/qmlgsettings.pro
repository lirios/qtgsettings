TARGET = tst_qmlgsettings

QT += testlib Qt5GSettings

CONFIG += qmltestcase

DEFINES += TEST_DATADIR=\\\"$${_PRO_FILE_PWD_}/../data\\\"

SOURCES += \
    $$PWD/tst_qmlgsettings.cpp

IMPORTPATH = $$QTGSETTINGS_BUILD_DIR/qml
