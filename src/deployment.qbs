import qbs 1.0

Project {
    name: "Deployment"

    InstallPackage {
        name: "qtgsettings-artifacts"
        targetName: name
        builtByDefault: false

        archiver.type: "tar"
        archiver.outputDirectory: project.buildDirectory

        Depends { name: "Qt5GSettings" }
        Depends { name: "Qt5GSettings-cmake" }
        Depends { name: "Qt5GSettings-pkgconfig" }
        Depends { name: "Qt5GSettings-qbs" }
        Depends { name: "qtgsettingsplugin" }
    }
}
