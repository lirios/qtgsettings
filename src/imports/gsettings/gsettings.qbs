import qbs 1.0

LiriQmlPlugin {
    name: "qtgsettingsplugin"
    pluginPath: "QtGSettings"

    Depends { name: "Qt5GSettings" }

    files: ["*.cpp", "*.h", "qmldir", "*.qmltypes"]
}
