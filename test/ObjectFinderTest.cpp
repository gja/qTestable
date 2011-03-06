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

      finder.insert("foo", &object);
      QCOMPARE(finder.find("foo").targetObject, &object);

      finder.remove("foo");
      QCOMPARE(finder.find("foo").targetObject, (QObject *) NULL);
    }

    void shouldReturnAMessageIfUnableToFindTopLevelObject()
    {
      ObjectFinder finder;
      QObject object;

      finder.insert("foo", &object);
      QCOMPARE(finder.find("foo").errorMessage, QString(""));

      finder.remove("foo");
      QCOMPARE(finder.find("foo").errorMessage, QString("Unable to find top level object \"foo\""));
    }

    void shouldBeAbleToFindSecondAndThirdLevelObject()
    {
      ObjectFinder finder;
      QObject first; first.setObjectName("foo");
      QObject second(&first); second.setObjectName("bar");
      QObject third(&second); third.setObjectName("baz");

      finder.insert("foo", &first);

      QCOMPARE(finder.find("foo/bar").targetObject, &second);
      QCOMPARE(finder.find("foo/bar/baz").targetObject, &third);

      QCOMPARE(finder.find("foo/baz").targetObject, &third);
    }

    void shouldReturnAnErrorIfUnableToFindObjectOfName()
    {
      ObjectFinder finder;
      QObject first; first.setObjectName("foo");

      finder.insert("foo", &first);

      QCOMPARE(finder.find("foo/unknown").targetObject, (QObject *) NULL);
      QCOMPARE(finder.find("foo/unknown").errorMessage, QString("Unable to find object \"unknown\""));
      QCOMPARE(finder.find("foo/unknown/blah").errorMessage, QString("Unable to find object \"unknown\""));
    }
};

QTEST_MAIN(ObjectFinderTest)
#include "ObjectFinderTest.moc"
