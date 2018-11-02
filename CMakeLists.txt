cmake_minimum_required(VERSION 3.10.0)

project("QtGSettings"
    VERSION "1.0.0"
    DESCRIPTION "Qt style API for GSettings"
    LANGUAGES CXX C
)

## Shared macros and functions:
if(NOT LIRI_LOCAL_ECM)
    find_package(LiriCMakeShared "1.0.0" REQUIRED NO_MODULE)
    list(APPEND CMAKE_MODULE_PATH "${LCS_MODULE_PATH}")
endif()

## Set minimum versions required:
set(QT_MIN_VERSION "5.8.0")

## Add some paths to check for CMake modules:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

## Liri specific setup common for all modules:
include(LiriSetup)

## Packaging:
include(LiriCPack)

## Find Qt 5:
find_package(Qt5 "${QT_MIN_VERSION}"
    CONFIG REQUIRED
    COMPONENTS
        Core
        Qml
        Quick
        QuickTest
)

## Add subdirectories:
add_subdirectory(src/gsettings)
add_subdirectory(src/imports/gsettings)
if(BUILD_TESTING)
    if(TARGET Qt5GSettings)
        add_subdirectory(tests/auto/gsettings)
    endif()
    if(TARGET qtgsettings)
        add_subdirectory(tests/auto/qmlgsettings)
    endif()
endif()
