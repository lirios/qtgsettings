/****************************************************************************
 * This file is part of Qt GSettings.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:GPL2+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QtTest/QtTest>

#include <Qt5GSettings/QGSettings>

using namespace QtGSettings;

class TestQGSettings : public QObject
{
    Q_OBJECT
public:
    TestQGSettings(QObject *parent = 0)
        : QObject(parent)
        , settings(nullptr)
    {
    }

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("GSETTINGS_BACKEND", "memory");
        qputenv("GSETTINGS_SCHEMA_DIR", QByteArrayLiteral(TEST_DATADIR));
        qDebug() << "Using backend:" << qgetenv("GSETTINGS_BACKEND");
        qDebug() << "Using schema directory:" << qgetenv("GSETTINGS_SCHEMA_DIR");
        QCOMPARE(qgetenv("GSETTINGS_BACKEND"), QByteArrayLiteral("memory"));

        QVERIFY2(QGSettings::isSchemaInstalled(QStringLiteral("io.liri.gsettings.test")),
                 "Schema io.liri.gsettings.test must be installed");

        settings = new QGSettings(QStringLiteral("io.liri.gsettings.test"),
                                  QStringLiteral("/io/liri/gsettings/test/"));
        QVERIFY2(settings->isValid(), "Settings for io.liri.gsettings.test must be valid");
    }

    void cleanupTestCase()
    {
        if (settings)
            settings->deleteLater();
    }

    void gVariantToQVariant_data()
    {
        QTest::addColumn<QString>("name");

        QTest::newRow("boolean") << "testBoolean";
        QTest::newRow("integer") << "testInteger";
        QTest::newRow("double") << "testDouble";
        QTest::newRow("string") << "testString";
        QTest::newRow("choices") << "testChoices";
        QTest::newRow("string-list") << "testStringList";
        QTest::newRow("string-map") << "testStringMap";
        QTest::newRow("integer-map") << "testIntegerMap";
    }

    void gVariantToQVariant()
    {
        QFETCH(QString, name);

        QVariant value = settings->defaultValue(name);
        QVERIFY(value.isValid());
    }

    void readBoolean()
    {
        QVariant value = settings->defaultValue(QStringLiteral("testBoolean"));
        QCOMPARE(value.toBool(), true);
    }

    void readInteger()
    {
        QVariant value = settings->defaultValue(QStringLiteral("testInteger"));
        QCOMPARE(value.toInt(), 42);
    }

    void readDouble()
    {
        QVariant value = settings->defaultValue(QStringLiteral("testDouble"));
        QCOMPARE(value.toDouble(), 42.69);
    }

    void readString()
    {
        QVariant value = settings->defaultValue(QStringLiteral("testString"));
        QCOMPARE(value.toString(), QStringLiteral("howdy?"));
    }

    void readChoices()
    {
        QVariant value = settings->defaultValue(QStringLiteral("testChoices"));
        QCOMPARE(value.toString(), QStringLiteral("one"));
    }

    void readStringList()
    {
        QStringList cmpValue = QStringList()
            << QStringLiteral("one") << QStringLiteral("two") << QStringLiteral("three");
        QVariant value = settings->defaultValue(QStringLiteral("testStringList"));
        QCOMPARE(value.toStringList(), cmpValue);
    }

    void readStringMap()
    {
        QMap<QString, QVariant> cmpValue;
        cmpValue.insert(QStringLiteral("key1"), QStringLiteral("value1"));
        cmpValue.insert(QStringLiteral("key2"), QStringLiteral("value2"));
        QVariant value = settings->defaultValue(QStringLiteral("testStringMap"));
        QCOMPARE(value.toMap(), cmpValue);
    }

    void readIntegerMap()
    {
        QMap<QString, QVariant> cmpValue;
        cmpValue.insert(QStringLiteral("key1"), 1);
        cmpValue.insert(QStringLiteral("key2"), 2);
        QVariant value = settings->defaultValue(QStringLiteral("testIntegerMap"));
        QCOMPARE(value.toMap(), cmpValue);
    }

    void setValue_data()
    {
        QTest::addColumn<QString>("name");
        QTest::addColumn<QVariant>("value");

        QTest::newRow("boolean") << "testBoolean" << QVariant(false);
        QTest::newRow("integer") << "testInteger" << QVariant(69);
        QTest::newRow("double") << "testDouble" << QVariant(69.42);
        QTest::newRow("string") << "testString" << QVariant(QStringLiteral("hello"));
        QTest::newRow("choices") << "testChoices" << QVariant(QStringLiteral("three"));
        QStringList stringList = QStringList()
            << QStringLiteral("another") << QStringLiteral("value");
        QTest::newRow("string-list") << "testStringList" << QVariant(stringList);
        QMap<QString, QVariant> stringMap;
        stringMap.insert(QStringLiteral("another-key1"), QStringLiteral("one"));
        stringMap.insert(QStringLiteral("another-key2"), QStringLiteral("two"));
        QTest::newRow("string-map") << "testStringMap" << QVariant(stringMap);
        QMap<QString, QVariant> intMap;
        intMap.insert(QStringLiteral("another-key1"), 1);
        intMap.insert(QStringLiteral("another-key2"), 2);
        QTest::newRow("integer-map") << "testIntegerMap" << QVariant(intMap);
    }

    void setValue()
    {
        QFETCH(QString, name);
        QFETCH(QVariant, value);

        settings->setValue(name, value);
        QCOMPARE(settings->value(name), value);
    }

    void keysList()
    {
        QStringList keys = settings->keys();
        keys.sort();

        QStringList cmpKeys = QStringList()
            << QStringLiteral("testBoolean") << QStringLiteral("testInteger")
            << QStringLiteral("testDouble") << QStringLiteral("testString")
            << QStringLiteral("testChoices") << QStringLiteral("testStringList")
            << QStringLiteral("testStringMap") << QStringLiteral("testIntegerMap");
        cmpKeys.sort();

        QCOMPARE(keys, cmpKeys);
    }

    void setOutOfRangeValue()
    {
        // Make sure test-choices contains a known value
        settings->setValue(QStringLiteral("testChoices"), QStringLiteral("one"));

        // Set a value that is out of range
        settings->setValue(QStringLiteral("testChoices"), QStringLiteral("four"));

        // Now the reported value should not be changed
        QCOMPARE(settings->value(QStringLiteral("testChoices")).toString(), QStringLiteral("one"));
    }

    void invalidSchemaNotInstalled()
    {
        QVERIFY2(!QGSettings::isSchemaInstalled(QStringLiteral("io.liri.gsettings.invalid.test")),
                 "Schema io.liri.gsettings.invalid.test must not be installed");
    }

    void invalidSchema()
    {
        QSKIP("Skipped because gio crashes");

        QGSettings *invalidSettings =
            new QGSettings(QStringLiteral("io.liri.gsettings.invalid.test"));
        QVERIFY2(!invalidSettings->isValid(),
                 "Settings for io.liri.gsettings.invalidtest must not be valid");
        invalidSettings->deleteLater();
    }

    void invalidPath()
    {
        QSKIP("Skipped because gio crashes");

        QGSettings *invalidSettings =
            new QGSettings(QStringLiteral("io.liri.gsettings.test"),
                           QStringLiteral("/io/liri/gsettings/invalid/test/"));
        QVERIFY2(!invalidSettings->isValid(),
                 "Path /io/liri/gsettings/invalid/test must not be found");
        invalidSettings->deleteLater();
    }

    void invalidKey()
    {
        QCOMPARE(settings->value(QStringLiteral("keyThatDoesNotExist")), QVariant());
    }

private:
    QGSettings *settings;
};

QTEST_MAIN(TestQGSettings)

#include "tst_qgsettings.moc"
