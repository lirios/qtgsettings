import qbs 1.0
import qbs.Probes

LiriModule {
    name: "libQtGSettings"

    targetName: "Qt5GSettings"
    version: "1.0.0"

    Depends { name: "Qt.core" }

    cpp.defines: base.concat(["QT_NO_KEYWORDS"])
    cpp.cxxFlags: base.concat(pkgConfig.cflags)
    cpp.linkerFlags: base.concat(pkgConfig.libs)
    // FIXME: For some reasone the above instruction is not enough
    cpp.dynamicLibraries: ["glib-2.0", "gio-2.0", "gobject-2.0"]

    create_headers.headersMap: ({
        "qgsettings.h": "QGSettings",
    })

    create_pkgconfig.name: "Qt GSettings"
    create_pkgconfig.description: "Qt-style wrapper for GSettings"
    create_pkgconfig.version: project.version
    create_pkgconfig.dependencies: ["Qt5Core", "gio-2.0"]

    create_cmake.version: project.version
    create_cmake.dependencies: ({
        "Qt5Core": "5.6"
    })
    create_cmake.linkLibraries: ["Qt5::Core"]

    Probes.PkgConfigProbe {
        id: pkgConfig
        name: "gio-2.0"
    }

    condition: pkgConfig.found

    files: ["*.cpp"]

    Group {
        name: "Headers"
        files: ["*.h"]
        excludeFiles: ["*_p.h"]
        fileTags: ["public_headers"]
    }

    Group {
        name: "Private Headers"
        files: ["*_p.h"]
        fileTags: ["private_headers"]
    }

    Export {
        Depends { name: "cpp" }
        Depends { name: "Qt.core" }

        cpp.defines: product.projectFileUpdateDefines
        cpp.includePaths: product.generatedHeadersDir
        // FIXME: For some reasone the above instruction is not enough
        cpp.dynamicLibraries: ["glib-2.0", "gio-2.0", "gobject-2.0"]
    }
}
