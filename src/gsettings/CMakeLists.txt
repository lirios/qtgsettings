liri_add_module(Qt6GSettings
    DESCRIPTION
        "Qt style API for GSettings"
    MODULE_NAME
        Qt6GSettings
    VERSIONED_MODULE_NAME
        Qt6GSettings
    SOURCES
        logging_p.h
        qgsettings.cpp qgsettings.h
        qgvariantutils_p.cpp qgvariantutils_p.h
        utils_p.cpp utils_p.h
    PRIVATE_HEADERS
        qgvariantutils_p.h
    PUBLIC_LIBRARIES
        Qt6::Core
    LIBRARIES
        PkgConfig::GIO
    PKGCONFIG_DEPENDENCIES
        Qt6Core
        gio-2.0
)

liri_finalize_module(Qt6GSettings)
