!exists(features/liri_deployment.prf): \
    error("Git submodule missing. Run \'git submodule update --init\' in $${PWD}.")

TEMPLATE = subdirs

SUBDIRS += src tests

tests.depends = src

OTHER_FILES += \
    $$PWD/AUTHORS.md \
    $$PWD/LICENSE.LGPLv3 \
    $$PWD/README.md
