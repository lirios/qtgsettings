import qbs 1.0

LiriDynamicLibrary {
    name: "QtGSettings"
    targetName: "qtgsettingsplugin"

    Depends { name: "lirideployment" }
    Depends { name: "Qt"; submodules: ["qml", "quick"] }
    Depends { name: "Qt5GSettings" }

    files: ["*.cpp", "*.h"]

    Group {
        name: "QML Files"
        files: [
            "qmldir",
            "plugins.qmltypes"
        ]
        fileTags: ["qml"]
    }

    Group {
        qbs.install: true
        qbs.installDir: lirideployment.qmlDir + "/QtGSettings"
        fileTagsFilter: ["dynamiclibrary", "qml"]
    }
}
