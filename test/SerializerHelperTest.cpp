#include <QTest>
#include "Helper.h"

using namespace QTestable;

class SerializerHelperTest : public QObject
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
};

QTEST_MAIN(SerializerHelperTest)
#include "SerializerHelperTest.moc"
