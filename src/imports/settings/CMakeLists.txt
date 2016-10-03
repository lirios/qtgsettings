include_directories(
    "${CMAKE_CURRENT_BINARY_DIR}/../../src"
    "${CMAKE_CURRENT_BINARY_DIR}/../../src/settings"
    "${CMAKE_CURRENT_BINARY_DIR}/../../src/settings/Vibe"
)

set(SOURCES
    plugin.cpp
    qmlgsettings.cpp
    qmlgsettingsschema.cpp
)

add_library(hawaiisettings SHARED ${SOURCES})
target_link_libraries(hawaiisettings
                      Qt5::Core
                      Qt5::Gui
                      Qt5::Qml
                      Qt5::Quick
                      Vibe::Settings)

install(TARGETS hawaiisettings
        LIBRARY DESTINATION ${QML_INSTALL_DIR}/Vibe/Settings)
install(FILES qmldir plugins.qmltypes
        DESTINATION ${QML_INSTALL_DIR}/Vibe/Settings)
