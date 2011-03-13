#include <QTest>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "MenuHelper.h"

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
      QCOMPARE (map["type"].toString(), QString("action"));
      QCOMPARE (map["text"].toString(), QString("foo"));
    }

    void shouldBeAbleToGetTitleAndTextForAQMenu()
    {
      QMenu menu("foo", NULL);
      menu.setObjectName("fooMenu");

      QVariantMap map = extractMenus(menu.menuAction()).toMap();
      QCOMPARE (map["name"].toString(), QString("fooMenu"));
      QCOMPARE (map["title"].toString(), QString("foo"));
      QCOMPARE (map["type"].toString(), QString("menu"));
    }

    void shouldBeAbleToGetChildrenForAQMenu()
    {
      QMenu menu("foo", NULL);
      QAction action1("action1", NULL);
      QAction action2("action2", NULL);

      menu.addAction(&action1);
      menu.addAction(&action2);

      QVariantMap map = extractMenus(menu.menuAction()).toMap();
      QList<QVariant> children = map["children"].toList();

      QCOMPARE(children[0].toMap()["text"].toString(), QString("action1"));
      QCOMPARE(children[1].toMap()["text"].toString(), QString("action2"));
    }

    void shouldBeAbleToGetChildrenForAQMenuBar()
    {
      QMenuBar menu(NULL);
      menu.setObjectName("menu");
      menu.addMenu(new QMenu("menu1", NULL));
      menu.addAction(new QAction("action2", NULL));
      menu.addMenu(new QMenu("menu3", NULL));

      QVariantMap map = extractMenus(&menu).toMap();

      QCOMPARE(map["name"].toString(), QString("menu"));
      QCOMPARE(map["type"].toString(), QString("menuBar"));

      QList<QVariant> children = map["children"].toList();
      QCOMPARE(children[0].toMap()["title"].toString(), QString("menu1"));
      QCOMPARE(children[1].toMap()["text"].toString(), QString("action2"));
      QCOMPARE(children[2].toMap()["title"].toString(), QString("menu3"));
    }
};

QTEST_MAIN(MenuHelperTest)
#include "MenuHelperTest.moc"
