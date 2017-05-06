import qbs 1.0

QtApplication {
    name: "tst_qmlgsettings"
    type: base.concat(["autotest"])

    Depends { name: "Qt"; submodules: ["core", "gui", "testlib", "qmltest"] }
    Depends { name: "libQtGSettings" }

    cpp.defines: ['TEST_DATADIR="' + product.sourceDirectory + '/../data"']

    files: ["*.cpp"]
}
