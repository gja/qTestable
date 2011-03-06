#include <QTest>
#include "ObjectFinder.h"

using namespace QTestable;

class ObjectFinderTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBehaveLikeADictonary()
    {
      ObjectFinder finder;
      QObject object;
      object.setObjectName("foo");

      finder.insert("foo", &object);
      QCOMPARE(finder.find("foo").targetObject->objectName(), QString("foo"));

      finder.remove("foo");
      QCOMPARE(finder.find("foo").targetObject, (QObject *) NULL);
    }

    void shouldReturnAMessageIfUnableToFindTopLevelObject()
    {
      ObjectFinder finder;
      QObject object;
      object.setObjectName("foo");

      finder.insert("foo", &object);
      QCOMPARE(finder.find("foo").errorMessage, QString(""));

      finder.remove("foo");
      QCOMPARE(finder.find("foo").errorMessage, QString("Unable to find top level object \"foo\""));
    }
};

QTEST_MAIN(ObjectFinderTest)
#include "ObjectFinderTest.moc"
