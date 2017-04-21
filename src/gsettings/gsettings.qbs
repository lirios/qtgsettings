import qbs 1.0
import qbs.Probes
import qbs.TextFile
import qbs.FileInfo

DynamicLibrary {
    name: "QtGSettings"

    property string headersDir: publicHeaders.qbs.installRoot + "/include"

    Depends { name: "cpp" }
    Depends { name: "Qt"; submodules: ["core"] }

    cpp.defines: base.concat(["QT_NO_KEYWORDS"])
    cpp.includePaths: base.concat(publicHeaders.qbs.installRoot + "/include")
    cpp.cxxFlags: pkgConfig.cflags
    cpp.linkerFlags: pkgConfig.libs
    // FIXME: For some reasone the above instruction is not enough
    cpp.dynamicLibraries: ["glib-2.0", "gio-2.0", "gobject-2.0"]

    Probes.PkgConfigProbe {
        id: pkgConfig
        name: "gio-2.0"
    }

    condition: pkgConfig.found

    files: [
        "qgsettings.cpp",
        "qgvariantutils.cpp",
        "utils.cpp"
    ]

    Group {
        id: publicHeaders
        name: "public headers"
        files: [
            "lirigsettingsglobal.h",
            "qgsettings.h"
        ]
        //fileTags: ["public_headers"]
        qbs.install: true
        qbs.installDir: "include/QtGSettings"
    }

    /*
    Group {
        fileTagsFilter: "class_headers"
        qbs.install: true
        qbs.installDir: "include/QtGSettings"
    }
    */

    Group {
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: "lib"
    }

    /*
    Rule {
        inputs: ["public_headers"]
        alwaysRun: true

        Artifact {
            filePath: {
                var destDir = product.headersDir + "/QtGSettings";

                // TODO: This is a hack
                if (input.fileName == "lirigsettingsglobal.h")
                    return "QtGSettingsGlobal";
                else if (input.fileName == "qgsettings.h")
                    return "QGSettings";

                // Camel case on a single word, of course it doesn't work
                var camelCase = function(w) {
                    return w[0].toUpperCase() + w.slice(1).toLowerCase();
                };
                var baseName = FileInfo.completeBaseName(input.fileName);
                return destDir + "/" + baseName.replace(/\w+/g, camelCase);
            }
            fileTags: ["hpp"]
            alwaysUpdated: true
        }

        prepare: {
            var cmd = new JavaScriptCommand();
            cmd.description = "Creating class header " + output.fileName;
            cmd.highlight = "codegen";
            cmd.sourceCode = function() {
                var content = '#include "' + input.fileName + '"';
                var file = new TextFile(output.filePath, TextFile.WriteOnly);
                file.write(content);
                file.close();
            }
            return [cmd];
        }
    }
    */

    Export {
        Depends { name: "cpp" }
        cpp.defines: product.projectFileUpdateDefines
        cpp.includePaths: base.concat(publicHeaders.qbs.installRoot + "/include")
    }
}
