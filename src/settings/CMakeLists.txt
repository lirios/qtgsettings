include_directories(
    ${CMAKE_BINARY_DIR}/headers
    ${CMAKE_CURRENT_BINARY_DIR}
    ${gio_INCLUDE_DIRS}
)

add_definitions(-DQT_NO_KEYWORDS)

set(SOURCES
    qgvariantutils.cpp
    qgsettings.cpp
    utils.cpp
)

add_library(HawaiiSettings SHARED ${SOURCES})
add_library(Hawaii::Settings ALIAS HawaiiSettings)

target_link_libraries(HawaiiSettings
    PUBLIC
        Qt5::Core
    PRIVATE
        ${gio_LIBRARIES}
)

##############################################################################

generate_export_header(HawaiiSettings EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/Hawaii/Settings/hawaii_settings_export.h)

target_include_directories(HawaiiSettings INTERFACE "$<INSTALL_INTERFACE:${HAWAII_INCLUDEDIR}>")

set_target_properties(HawaiiSettings PROPERTIES
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_SOVERSION}
                      EXPORT_NAME Settings)

ecm_generate_headers(HawaiiSettings_CamelCase_HEADERS
  HEADER_NAMES
    QGSettings
  PREFIX
    Settings
  REQUIRED_HEADERS
    HawaiiSettings_HEADERS
  OUTPUT_DIR
    ${CMAKE_CURRENT_BINARY_DIR}/Hawaii
)
install(FILES ${HawaiiSettings_CamelCase_HEADERS}
        DESTINATION ${HAWAII_INCLUDEDIR}/Settings
        COMPONENT Devel)

install(TARGETS HawaiiSettings EXPORT HawaiiSettingsTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/Hawaii/Settings/hawaii_settings_export.h
      ${HawaiiSettings_HEADERS}
      qgsettings.h
    DESTINATION
      ${HAWAII_INCLUDEDIR}/settings
    COMPONENT
      Devel
)

install(EXPORT HawaiiSettingsTargets
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        FILE HawaiiSettingsTargets.cmake NAMESPACE Hawaii::)
