add_executable(tst_gsettings tst_qgsettings.cpp)

target_compile_definitions(tst_gsettings PRIVATE TEST_DATADIR="${CMAKE_CURRENT_SOURCE_DIR}/../data")

target_link_libraries(tst_gsettings PRIVATE Qt6::Test Liri::Qt6GSettings)
