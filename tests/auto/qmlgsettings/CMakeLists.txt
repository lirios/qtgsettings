liri_add_test(tst_qmlgsettings
    SOURCES
        tst_qmlgsettings.cpp
        tst_qmlgsettings.qml
    DEFINES
        TEST_DATADIR="${CMAKE_CURRENT_SOURCE_DIR}/../data"
    LIBRARIES
        Qt5::QuickTest
        Liri::Qt5GSettings
)
