import qbs 1.0

QtApplication {
    name: "tst_gsettings"
    condition: project.autotestEnabled
    type: base.concat(["autotest"])

    Depends { name: "Qt"; submodules: ["core", "testlib"]; versionAtLeast: project.minimumQtVersion }
    Depends { name: "Qt5GSettings" }

    cpp.defines: ['TEST_DATADIR="' + product.sourceDirectory + '/../data"']

    files: ["*.cpp"]
}
