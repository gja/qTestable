#include <QTest>
#include "Helper.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

using namespace QTestable;

class MenuHelperTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBeAbleToGetNameAndTextForAQAction()
    {
      QAction action("foo", NULL);
      action.setObjectName("fooAction");

      QVariantMap map = extractMenus(&action).toMap();
      QCOMPARE (map["name"].toString(), QString("fooAction"));
      QCOMPARE (map["text"].toString(), QString("foo"));
      QCOMPARE (map["type"].toString(), QString("action"));
    }

    void shouldBeAbleToGetTitleAndTextForAQMenu()
    {
      QMenu menu("foo", NULL);
      menu.setObjectName("fooMenu");

      QVariantMap map = extractMenus(&menu).toMap();
      QCOMPARE (map["name"].toString(), QString("fooMenu"));
      QCOMPARE (map["title"].toString(), QString("foo"));
      QCOMPARE (map["type"].toString(), QString("menu"));
    }

    void shouldBeAbleToGetChildrenForAQMenu()
    {
      QMenu menu("foo", NULL);
      QAction action1("action1", &menu);
      QAction action2("action2", &menu);

      QVariantMap map = extractMenus(&menu).toMap();
      QList<QVariant> children = map["children"].toList();

      // For some reason, it contains an action with itself
      QCOMPARE(children[0].toMap()["type"].toString(), QString("action"));
      QCOMPARE(children[0].toMap()["text"].toString(), QString("foo"));

      QCOMPARE(children[1].toMap()["text"].toString(), QString("action1"));
      QCOMPARE(children[2].toMap()["text"].toString(), QString("action2"));
    }

    
    void shouldBeAbleToGetChildrenForAQMenuBar()
    {
      QMenuBar menu(NULL);
      QMenu menu1("menu1", &menu);
      QMenu menu2("menu2", &menu);

      QVariantMap map = extractMenus(&menu).toMap();
      QList<QVariant> children = map["children"].toList();

      QCOMPARE (map["type"].toString(), QString("menuBar"));

      // Automatically added again
      QCOMPARE(children[0].toMap()["name"].toString(), QString("qt_menubar_ext_button"));

      QCOMPARE(children[1].toMap()["title"].toString(), QString("menu1"));
      QCOMPARE(children[2].toMap()["title"].toString(), QString("menu2"));
    }
};

QTEST_MAIN(MenuHelperTest)
#include "MenuHelperTest.moc"
