/****************************************************************************
 * This file is part of Qt GSettings.
 *
 * Copyright (C) 2017 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL3$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#pragma once

#include <QtCore/qglobal.h>

#if defined(QT_BUILD_QTGSETTINGS_LIB)
#  define QTGSETTINGS_EXPORT Q_DECL_EXPORT
#else
#  define QTGSETTINGS_EXPORT Q_DECL_IMPORT
#endif
#define QTGSETTINGS_NO_EXPORT Q_DECL_HIDDEN
