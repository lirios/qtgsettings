TARGET = tst_qgsettings

QT += testlib QtGSettings

CONFIG += testcase

DEFINES += TEST_DATADIR=\\\"$${_PRO_FILE_PWD_}/../data\\\"

SOURCES += \
    $$PWD/tst_qgsettings.cpp
