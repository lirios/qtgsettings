import qbs 1.0

LoadableModule {
    name: "qtgsettingsplugin"

    Depends { name: "cpp" }
    Depends { name: "Qt"; submodules: ["qml", "quick"] }
    Depends { name: "QtGSettings" }

    files: [
        "plugin.cpp",
        "qmlgsettings.cpp",
        "qmlgsettingsschema.cpp"
    ]

    Group {
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: "qml/QtGSettings"
    }

    Export {
        Depends { name: "cpp" }
        cpp.defines: product.projectFileUpdateDefines
    }
}
