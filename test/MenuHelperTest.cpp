#include <QTest>
#include "Helper.h"
#include <QAction>

using namespace QTestable;

class MenuHelperTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBeAbleToGetNameAndTextForAQAction()
    {
      QAction action("foo", NULL);
      action.setObjectName("fooAction");

      QVariantMap map = Helper::extractMenus(&action);
      QCOMPARE (map["name"].toString(), QString("fooAction"));
      QCOMPARE (map["text"].toString(), QString("foo"));
    }
};

QTEST_MAIN(MenuHelperTest)
#include "MenuHelperTest.moc"
