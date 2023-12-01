/****************************************************************************
 * This file is part of Qt GSettings.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#include <QQmlEngine>
#include <QQmlPropertyMap>
#include <QQmlParserStatus>

namespace QtGSettings {
class QGSettings;
}

class QmlGSettingsSchema;

class QmlGSettings : public QQmlPropertyMap, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QmlGSettingsSchema *schema READ schema NOTIFY schemaChanged)
    QML_NAMED_ELEMENT(GSettings)
    Q_MOC_INCLUDE("qmlgsettingsschema.h")
public:
    QmlGSettings(QObject *parent = nullptr);

    QmlGSettingsSchema *schema() const;

    void classBegin() override;
    void componentComplete() override;

Q_SIGNALS:
    void schemaChanged();
    void settingsChanged();

protected:
    QVariant updateValue(const QString &key, const QVariant &input) override;

private:
    QmlGSettingsSchema *m_schema;
    QtGSettings::QGSettings *m_settings;
};
