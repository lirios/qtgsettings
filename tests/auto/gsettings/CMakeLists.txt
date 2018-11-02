liri_add_test(tst_gsettings
    SOURCES
        tst_qgsettings.cpp
    DEFINES
        TEST_DATADIR="${CMAKE_CURRENT_SOURCE_DIR}/../data"
    LIBRARIES
        Liri::Qt5GSettings
)
