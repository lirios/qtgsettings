add_executable(tst_qmlgsettings
    tst_qmlgsettings.cpp
    tst_qmlgsettings.qml
)

target_compile_definitions(tst_qmlgsettings PRIVATE TEST_DATADIR="${CMAKE_CURRENT_SOURCE_DIR}/../data")

target_link_libraries(tst_qmlgsettings PRIVATE Qt6::QuickTest Liri::Qt6GSettings)
