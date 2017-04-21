import qbs 1.0

Project {
    references: [
        "src/gsettings/gsettings.qbs",
        "src/imports/gsettings/gsettings.qbs"
    ]

    Product {
        name: "qmake project files"
        files: [
            "**/*.pr[io]"
        ]
    }
}
