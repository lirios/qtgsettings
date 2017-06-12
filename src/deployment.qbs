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
        Depends { name: "qtgsettingsplugin" }
    }
}
