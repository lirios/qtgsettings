import qbs 1.0

Project {
    name: "QtGSettings"

    readonly property string version: "1.0.0"

    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.6"

    qbsSearchPaths: "qbs-shared"

    references: [
        "src/gsettings/gsettings.qbs",
        "src/imports/gsettings/gsettings.qbs",
        "tests/auto/auto.qbs"
    ]

    AutotestRunner {
        builtByDefault: true
        name: "qtgsettings-autotest"
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
    }
}
