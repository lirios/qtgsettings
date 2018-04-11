import qbs 1.0

Project {
    name: "QtGSettings"

    readonly property string version: "1.2.0"
    readonly property var versionParts: version.split('.').map(function(part) { return parseInt(part); })

    readonly property string minimumQtVersion: "5.8.0"

    property bool useStaticAnalyzer: false

    property bool autotestEnabled: false
    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.9.0"

    references: [
        "src/deployment.qbs",
        "src/gsettings/gsettings.qbs",
        "src/imports/imports.qbs",
        "tests/auto/auto.qbs"
    ]
}
