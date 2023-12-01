ecm_add_qml_module(QtGSettingsQmlModule
    URI
        "QtGSettings"
    VERSION
        "2.0"
    GENERATE_PLUGIN_SOURCE
)

target_sources(QtGSettingsQmlModule
    PRIVATE
        qmlgsettings.cpp qmlgsettings.h
        qmlgsettingsschema.cpp qmlgsettingsschema.h
)

target_link_libraries(QtGSettingsQmlModule
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Liri::Qt6GSettings
)

ecm_finalize_qml_module(QtGSettingsQmlModule)
