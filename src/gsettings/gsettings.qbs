import qbs 1.0
import qbs.Probes
import LiriUtils

LiriModuleProject {
    id: root

    name: "Qt5GSettings"
    moduleName: "Qt5GSettings"
    description: "Qt-style wrapper for GSettings"

    resolvedProperties: ({
        Depends: [{ name: LiriUtils.quote("Qt.core") },
                  { name: LiriUtils.quote("glib.gio") },
                  { name: LiriUtils.quote("glib.gobject") }],
    })

    pkgConfigDependencies: ["Qt5Core", "gio-2.0"]

    cmakeDependencies: ({ "Qt5Core": "5.6.0" })
    cmakeLinkLibraries: ["Qt5::Core"]

    LiriHeaders {
        name: root.headersName
        sync.module: root.moduleName

        Group {
            name: "Headers"
            files: "**/*.h"
            fileTags: ["hpp_syncable"]
        }
    }

    LiriModule {
        name: root.moduleName
        targetName: root.targetName
        version: "1.0.0"

        Depends { name: root.headersName }
        Depends { name: "Qt.core" }
        Depends { name: "glib"; submodules: ["gio", "gobject"] }

        condition: {
            if (!glib.gio.found || !glib.gobject) {
                console.error("glib-2.0 is required to build " + targetName);
                return false;
            }

            return true;
        }

        Qt.core.enableKeywords: false

        files: ["*.cpp", "*.h"]

        Export {
            Depends { name: "cpp" }
            Depends { name: root.headersName }
            Depends { name: "Qt.core" }
            Depends { name: "glib"; submodules: ["gio", "gobject"] }
        }
    }
}
