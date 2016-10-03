include_directories(
    "${CMAKE_CURRENT_BINARY_DIR}/../../headers"
    "${CMAKE_CURRENT_BINARY_DIR}"
    ${gio_INCLUDE_DIRS}
)

add_definitions(-DQT_NO_KEYWORDS)

set(SOURCES
    qgvariantutils.cpp
    qgsettings.cpp
    utils.cpp
)

add_library(VibeSettings SHARED ${SOURCES})
add_library(Vibe::Settings ALIAS VibeSettings)

target_link_libraries(VibeSettings
    PUBLIC
        Qt5::Core
    PRIVATE
        ${gio_LIBRARIES}
)

##############################################################################

generate_export_header(VibeSettings EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/Vibe/settings/vibe_settings_export.h")

target_include_directories(VibeSettings
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/Vibe>"
        "$<INSTALL_INTERFACE:${VIBE_INCLUDEDIR}>"
)

set_target_properties(VibeSettings PROPERTIES
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_SOVERSION}
                      EXPORT_NAME Settings)

ecm_generate_headers(VibeSettings_CamelCase_HEADERS
  HEADER_NAMES
    QGSettings
  PREFIX
    Settings
  REQUIRED_HEADERS
    VibeSettings_HEADERS
  OUTPUT_DIR
    "${CMAKE_CURRENT_BINARY_DIR}/Vibe"
)
install(FILES ${VibeSettings_CamelCase_HEADERS}
        DESTINATION ${VIBE_INCLUDEDIR}/Settings
        COMPONENT Devel)

install(TARGETS VibeSettings EXPORT VibeSettingsTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

install(
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/Vibe/settings/vibe_settings_export.h"
      ${VibeSettings_HEADERS}
      qgsettings.h
    DESTINATION
      ${VIBE_INCLUDEDIR}/settings
    COMPONENT
      Devel
)

install(EXPORT VibeSettingsTargets
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        FILE VibeSettingsTargets.cmake NAMESPACE Vibe::)
