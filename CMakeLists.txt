cmake_minimum_required(VERSION 3.19)

project("QtGSettings"
    VERSION "1.4.0"
    DESCRIPTION "Qt style API for GSettings"
    LANGUAGES CXX C
)

## Only build on the appropriate platforms.
if(NOT UNIX OR CMAKE_SYSTEM_NAME MATCHES "Android")
    message(NOTICE "Skipping the build as the condition \"UNIX OR Android\" is not met.")
    return()
endif()

## ECM:
find_package(ECM 5.245.0 REQUIRED NO_MODULE)
list(APPEND CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

## Installation directories:
include(KDEInstallDirs)

## Compiler settings:
set(KDE_SKIP_NULLPTR_WARNINGS_SETTINGS TRUE)
include(KDECompilerSettings NO_POLICY_SCOPE)

## Treat warnings as errors:
add_compile_options(-Wall -Wextra -Werror)

## CMake settings:
include(KDECMakeSettings)

## QML module:
include(ECMQmlModule)

## Shared macros and functions:
if(NOT LIRI_LOCAL_ECM)
    find_package(LiriCMakeShared "2.0.99" REQUIRED NO_MODULE)
    list(APPEND CMAKE_MODULE_PATH "${LCS_MODULE_PATH}")
endif()

## Add some paths to check for CMake modules:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

## Liri specific setup common for all modules:
include(LiriSetup)

## Features:
include(features.cmake)

## Project setup:
qt6_standard_project_setup(REQUIRES 6.6)

## Disable use of C++ API deprecated in Qt 5.15
add_compile_definitions(QT_DISABLE_DEPRECATED_UP_TO=0x050F00)

## QML import path:
if(NOT QML_IMPORT_PATH)
    set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR}/bin CACHE STRING "" FORCE)
endif()

## Add subdirectories:
add_subdirectory(src/gsettings)
if(TARGET Liri::Qt6GSettings)
    add_subdirectory(src/imports/gsettings)
endif()
if(BUILD_TESTING)
    if(TARGET Qt6GSettings)
        add_subdirectory(tests/auto/gsettings)
    endif()
    if(TARGET QtGSettingsQmlModule)
        add_subdirectory(tests/auto/qmlgsettings)
    endif()
endif()
