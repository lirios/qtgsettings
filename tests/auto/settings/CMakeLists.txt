include_directories(
    "${CMAKE_CURRENT_BINARY_DIR}/../../src"
    "${CMAKE_CURRENT_BINARY_DIR}/../../src/core"
    "${CMAKE_CURRENT_BINARY_DIR}/../../src/core/Vibe"
)

add_definitions(
    -DTEST_DATADIR="${CMAKE_CURRENT_SOURCE_DIR}/data/"
    -DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
)

set(tst_qgsettings_SRCS
    tst_qgsettings.cpp
)
add_executable(tst_qgsettings EXCLUDE_FROM_ALL ${tst_qgsettings_SRCS})
target_link_libraries(tst_qgsettings Qt5::Test Vibe::Settings)
add_test(tst_qgsettings tst_qgsettings)
add_dependencies(check tst_qgsettings)

set(tst_qmlgsettings_SRCS
    tst_qmlgsettings.cpp
)
add_executable(tst_qmlgsettings EXCLUDE_FROM_ALL ${tst_qmlgsettings_SRCS})
target_link_libraries(tst_qmlgsettings Qt5::Quick Qt5::QuickTest)
add_test(tst_qmlgsettings tst_qmlgsettings)
add_dependencies(check tst_qmlgsettings)
