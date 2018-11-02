#!/bin/bash

set -e

source /usr/local/share/liri-travis/functions

# Install artifacts
travis_start "artifacts"
msg "Install artifacts..."
/usr/local/bin/liri-download-artifacts $TRAVIS_BRANCH qbs-shared-artifacts.tar.gz
travis_end "artifacts"

# Configure qbs
travis_start "qbs_setup"
msg "Setup qbs..."
qbs setup-toolchains --detect
qbs setup-qt $(which qmake-qt5) travis-qt5
qbs config profiles.travis-qt5.baseProfile $CC
travis_end "qbs_setup"

# Build
travis_start "build"
msg "Build..."
dbus-run-session -- \
xvfb-run -a -s "-screen 0 800x600x24" \
qbs -d build -j $(nproc) --all-products profile:travis-qt5 \
    modules.lirideployment.prefix:/usr \
    modules.lirideployment.libDir:/usr/lib64 \
    modules.lirideployment.qmlDir:/usr/lib64/qt5/qml \
    modules.lirideployment.pluginsDir:/usr/lib64/qt5/plugins
travis_end "build"