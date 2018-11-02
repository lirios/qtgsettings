find_package(GIO REQUIRED)

liri_add_module(Qt5GSettings
    DESCRIPTION
        "Qt style API for GSettings"
    MODULE_NAME
        Qt5GSettings
    VERSIONED_MODULE_NAME
        Qt5GSettings
    SOURCES
        logging_p.h
        qgsettings.cpp
        qgsettings.h
        qgvariantutils_p.cpp
        qgvariantutils_p.h
        utils_p.cpp
        utils_p.h
    FORWARDING_HEADERS
        QGSettings
    PRIVATE_HEADERS
        qgvariantutils_p.h
    DEFINES
        QT_NO_CAST_FROM_ASCII
        QT_NO_FOREACH
        QT_NO_KEYWORDS
    PUBLIC_LIBRARIES
        Qt5::Core
    LIBRARIES
        PkgConfig::GIO
    PKGCONFIG_DEPENDENCIES
        Qt5Core
        gio-2.0
)
