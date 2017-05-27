import qbs 1.0

Project {
    name: "QtGSettings"

    readonly property string version: "1.0.0"

    property bool autotestEnabled: false
    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.6"

    qbsSearchPaths: "qbs/shared"

    references: [
        "src/gsettings/gsettings.qbs",
        "src/imports/gsettings/gsettings.qbs",
        "tests/auto/auto.qbs"
    ]

    AutotestRunner {
        builtByDefault: autotestEnabled
        name: "qtgsettings-autotest"
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
    }

    InstallPackage {
        name: "qtgsettings-artifacts"
        targetName: name
        builtByDefault: false

        archiver.type: "tar"
        archiver.outputDirectory: project.buildDirectory

        Depends { name: "Qt5GSettings" }
        Depends { name: "QtGSettings" }
    }
}
