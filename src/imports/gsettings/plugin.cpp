/****************************************************************************
 * This file is part of Qt GSettings.
 *
 * Copyright (C) 2017 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 * Copyright (C) 2016 Michael Spencer <sonrisesoftware@gmail.com>
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

#include <QtQml/QtQml>

#include "qmlgsettings.h"
#include "qmlgsettingsschema.h"

class QtGSettingsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri)
    {
        // @uri Liri.GSettings
        Q_ASSERT(QLatin1String(uri) == QLatin1String("QtGSettings"));

        qmlRegisterType<QmlGSettings>(uri, 1, 0, "GSettings");
        qmlRegisterUncreatableType<QmlGSettingsSchema>(
            uri, 1, 0, "GSettingsSchema",
            QStringLiteral("Cannot instantiate GSettingsSchema objects"));
    }
};

#include "plugin.moc"
