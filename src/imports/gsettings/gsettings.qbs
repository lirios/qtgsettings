import qbs 1.0

LiriDynamicLibrary {
    name: "qtgsettingsplugin"
    targetName: "qtgsettingsplugin"

    Depends { name: "lirideployment" }
    Depends { name: "Qt"; submodules: ["qml", "quick"] }
    Depends { name: "libQtGSettings" }

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
