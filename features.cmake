# SPDX-FileCopyrightText: 2023 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
# SPDX-License-Identifier: BSD-3-Clause

## Enable feature summary at the end of the configure run:
include(FeatureSummary)

## Find GIO:
find_package(GIO REQUIRED)

## Find Qt:
find_package(Qt6
    REQUIRED
    COMPONENTS
        Core
        Qml
        Quick
        QuickTest
)

#### Features

## Features summary:
if(NOT LIRI_SUPERBUILD)
    feature_summary(WHAT ENABLED_FEATURES DISABLED_FEATURES)
endif()
