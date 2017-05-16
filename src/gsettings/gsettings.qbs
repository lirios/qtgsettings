import qbs 1.0
import qbs.Probes

LiriModule {
    name: "Qt5GSettings"

    targetName: "Qt5GSettings"
    version: "1.0.0"

    Depends { name: "Qt.core" }
    Depends { name: "glib"; submodules: ["gio", "gobject"] }

    condition: {
        if (!glib.gio.found || !glib.gobject) {
            console.error("glib-2.0 is required to build " + targetName);
            return false;
        }

        return true;
    }

    cpp.defines: base.concat(["QT_NO_KEYWORDS"])

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
