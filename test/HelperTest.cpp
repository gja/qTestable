#include <QTest>
#include "Helper.h"

using namespace QTestable;

class HelperTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldSerializeAnInteger()
    {
      QCOMPARE(serialize(QVariant(4)), QString("4"));
    }

    void shouldSerializeAVariantMap()
    {
      QVariantMap map;
      map["a"] = "aValue";
      map["b"] = "bValue";
      QCOMPARE(serialize(map), QString("{ \"a\" : \"aValue\", \"b\" : \"bValue\" }"));
    }

    void shouldBeAbleToGetNameForASimpleObject()
    {
      QObject object;
      object.setObjectName("foo");
      QVariantMap map = extractChildrenTree(&object).toMap();

      QCOMPARE(map["name"].toString(), QString("foo"));
      QCOMPARE(map.contains("children"), false);
    }

    void shouldBeAbleToGetNameObjectWithChild()
    {
      QObject object; object.setObjectName("foo");
      QObject object2(&object); object2.setObjectName("foo2");
      QVariantMap map = extractChildrenTree(&object).toMap();

      QVariantMap child = map["children"].toList()[0].toMap();
      QCOMPARE(child["name"].toString(), QString("foo2"));
    }
};

QTEST_MAIN(HelperTest)
#include "HelperTest.moc"
