import qbs 1.0

Project {
    name: "Autotests"

    references: [
        "gsettings/gsettings.qbs",
    ]

    AutotestRunner {
        builtByDefault: project.autotestEnabled
        name: "qtgsettings-autotest"
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
    }
}
