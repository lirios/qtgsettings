/****************************************************************************
 * This file is part of Qt GSettings.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 * Copyright (C) 2013 Canonical Ltd.
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

#include <QtCore/QUrl>
#include <QtCore/QStringList>

#include "qgvariantutils_p.h"

namespace Utils {

QVariant toQVariant(GVariant *value)
{
    if (!value)
        return QVariant();

    switch (g_variant_classify(value)) {
    case G_VARIANT_CLASS_BOOLEAN:
        return QVariant((bool)g_variant_get_boolean(value));
    case G_VARIANT_CLASS_BYTE:
        return QVariant(QLatin1Char(g_variant_get_byte(value)));
    case G_VARIANT_CLASS_INT16:
        return QVariant((int)g_variant_get_int16(value));
    case G_VARIANT_CLASS_UINT16:
        return QVariant((uint)g_variant_get_uint16(value));
    case G_VARIANT_CLASS_INT32:
        return QVariant((int)g_variant_get_int32(value));
    case G_VARIANT_CLASS_UINT32:
        return QVariant((uint)g_variant_get_uint32(value));
    case G_VARIANT_CLASS_INT64:
        return QVariant((qlonglong)g_variant_get_int64(value));
    case G_VARIANT_CLASS_UINT64:
        return QVariant((qulonglong)g_variant_get_uint64(value));
    case G_VARIANT_CLASS_DOUBLE:
        return QVariant(g_variant_get_double(value));
    case G_VARIANT_CLASS_STRING:
        return QVariant(QString::fromUtf8(g_variant_get_string(value, NULL)));
    case G_VARIANT_CLASS_ARRAY:
        if (g_variant_is_of_type(value, G_VARIANT_TYPE_STRING_ARRAY)) {
            QStringList list;

            GVariantIter iter;
            g_variant_iter_init(&iter, value);

            const gchar *str;
            while (g_variant_iter_next(&iter, "&s", &str))
                list.append(QString::fromUtf8(str));

            return list;
        } else if (g_variant_is_of_type(value, G_VARIANT_TYPE_BYTESTRING_ARRAY)) {
            QByteArrayList list;

            GVariantIter iter;
            g_variant_iter_init(&iter, value);

            const gchar *item;
            while (g_variant_iter_next(&iter, "&y", &item))
                list.append(QByteArray(item));

            return QVariant::fromValue(list);
        } else if (g_variant_is_of_type(value, G_VARIANT_TYPE_BYTESTRING)) {
            return QVariant(QByteArray(g_variant_get_bytestring(value)));
        } else if (g_variant_is_of_type(value, G_VARIANT_TYPE("a{ss}"))) {
            QMultiMap<QString, QVariant> stringMap;

            GVariantIter iter;
            g_variant_iter_init(&iter, value);

            const gchar *key;
            const gchar *val;
            while (g_variant_iter_next(&iter, "{&s&s}", &key, &val))
                stringMap.insert(QString::fromUtf8(key), QVariant(QString::fromUtf8(val)));

            return QVariant::fromValue(stringMap);
        } else if (g_variant_is_of_type(value, G_VARIANT_TYPE("a{si}"))) {
            QMultiMap<QString, QVariant> intMap;

            GVariantIter iter;
            g_variant_iter_init(&iter, value);

            const gchar *key;
            int val;
            while (g_variant_iter_next(&iter, "{&si}", &key, &val))
                intMap.insert(QString::fromUtf8(key), QVariant(val));

            return QVariant::fromValue(intMap);
        }
    default:
        break;
    }

    return QVariant();
}

GVariant *toGVariant(const GVariantType *type, const QVariant &variant)
{
    switch (g_variant_type_peek_string(type)[0]) {
    case G_VARIANT_CLASS_BOOLEAN:
        return g_variant_new_boolean(variant.toBool());
    case G_VARIANT_CLASS_BYTE:
        return g_variant_new_byte(variant.toChar().toLatin1());
    case G_VARIANT_CLASS_INT16:
        return g_variant_new_int16(variant.toInt());
    case G_VARIANT_CLASS_UINT16:
        return g_variant_new_uint16(variant.toInt());
    case G_VARIANT_CLASS_INT32:
        return g_variant_new_int32(variant.toInt());
    case G_VARIANT_CLASS_UINT32:
        return g_variant_new_uint32(variant.toUInt());
    case G_VARIANT_CLASS_INT64:
        return g_variant_new_int64(variant.toLongLong());
    case G_VARIANT_CLASS_UINT64:
        return g_variant_new_uint64(variant.toULongLong());
    case G_VARIANT_CLASS_DOUBLE:
        return g_variant_new_double(variant.toDouble());
    case G_VARIANT_CLASS_STRING:
        return g_variant_new_string(variant.toString().toUtf8().constData());
    case G_VARIANT_CLASS_ARRAY:
        if (g_variant_type_equal(type, G_VARIANT_TYPE_STRING_ARRAY)) {
            GVariantBuilder builder;
            g_variant_builder_init(&builder, G_VARIANT_TYPE_STRING_ARRAY);
            const QStringList list = variant.toStringList();
            for (const QString &item : std::as_const(list))
                g_variant_builder_add(&builder, "s", item.toUtf8().constData());

            return g_variant_builder_end(&builder);
        } else if (g_variant_type_equal(type, G_VARIANT_TYPE_BYTESTRING)) {
            return g_variant_new_bytestring(variant.toByteArray().constData());
        } else if (g_variant_type_equal(type, G_VARIANT_TYPE("a{ss}"))) {
            GVariantBuilder builder;
            g_variant_builder_init(&builder, G_VARIANT_TYPE("a{ss}"));

            QVariantMap map = variant.toMap();
            QVariantMap::const_iterator it = map.constBegin();
            while (it != map.constEnd()) {
                QByteArray key = it.key().toUtf8();
                QByteArray value = it.value().toByteArray();
                g_variant_builder_add(&builder, "{ss}", key.constData(), value.constData());

                ++it;
            }

            return g_variant_builder_end(&builder);
        } else if (g_variant_type_equal(type, G_VARIANT_TYPE("a{si}"))) {
            GVariantBuilder builder;
            g_variant_builder_init(&builder, G_VARIANT_TYPE("a{si}"));

            QVariantMap map = variant.toMap();
            QVariantMap::const_iterator it = map.constBegin();
            while (it != map.constEnd()) {
                QByteArray key = it.key().toUtf8();
                int value = it.value().toInt();
                g_variant_builder_add(&builder, "{si}", key.constData(), value);

                ++it;
            }

            return g_variant_builder_end(&builder);
        }
        break;
    default:
        return nullptr;
    }

    return 0;
}

} // namespace Utils
