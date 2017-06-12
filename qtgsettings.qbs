import qbs 1.0

Project {
    name: "QtGSettings"

    readonly property string version: "1.0.0"
    readonly property var versionParts: version.split('.').map(function(part) { return parseInt(part); })

    property bool autotestEnabled: false
    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.8"

    qbsSearchPaths: ["qbs/shared"]

    references: [
        "src/deployment.qbs",
        "src/gsettings/gsettings.qbs",
        "src/imports/imports.qbs",
        "tests/auto/auto.qbs"
    ]
}
