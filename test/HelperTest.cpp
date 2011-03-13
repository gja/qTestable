#include <QTest>
#include "Helper.h"

using namespace QTestable;

class HelperTest : public QObject
{
  Q_OBJECT
  private slots:
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
