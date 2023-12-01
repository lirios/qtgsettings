Qt GSettings
============

[![License](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](http://www.gnu.org/licenses/lgpl.txt)
[![GitHub release](https://img.shields.io/github/release/lirios/qtgsettings.svg)](https://github.com/lirios/qtgsettings)
[![GitHub issues](https://img.shields.io/github/issues/lirios/qtgsettings.svg)](https://github.com/lirios/qtgsettings/issues)
[![CI](https://github.com/lirios/qtgsettings/workflows/CI/badge.svg?branch=develop)](https://github.com/lirios/qtgsettings/actions?query=workflow%3ACI)

Qt-style API to wrap GSettings.

## Dependencies

Qt >= 6.6.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)

The following modules and their dependencies are required:

 * [cmake](https://gitlab.kitware.com/cmake/cmake) >= 3.19.0
 * [extra-cmake-modules](https://invent.kde.org/frameworks/extra-cmake-modules) >= 5.245.0
 * [cmake-shared](https://github.com/lirios/cmake-shared.git) >= 2.0.99
 * [glib](https://git.gnome.org/browse/glib) >= 2.31.0

## Installation

```sh
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/path/to/prefix ..
make
make install # use sudo if necessary
```

Replace `/path/to/prefix` to your installation prefix.
Default is `/usr/local`.

## Licensing

Licensed under the terms of the GNU Lesser General Public License version 3.
