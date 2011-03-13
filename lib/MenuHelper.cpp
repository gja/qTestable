#include "MenuHelper.h"
#include <QAction>
#include <QMenu>

namespace QTestable
{
  void populatePropertiesOfAction(const QAction *action, QVariantMap &map)
  {
    map["name"] = action->objectName();
    map["type"] = "action";
    map["text"] = action->text();
  }

  void populate_children(const QWidget *object, QVariantMap &map)
  {
    QList<QVariant> list;
    foreach(const QAction *action, object->actions())
      list<<extractMenus(action);
    map["children"] = list;
  }

  void populatePropertiesOfMenu(const QMenu *menu, QVariantMap &map)
  {
    map["name"] = menu->objectName();
    map["type"] = "menu";
    map["title"] = menu->title();

    populate_children(menu, map);
  }

  QVariant extractMenus(const QAction *object)
  {
    QVariantMap map;

    const QMenu *menu = object->menu();
    if(menu)
      populatePropertiesOfMenu(menu, map);
    else
      populatePropertiesOfAction(object, map);

    return map;
  }

  QVariant extractMenus(const QMenuBar *menuBar)
  {
    QVariantMap map;

    map["name"] = menuBar->objectName();
    map["type"] = "menuBar";

    populate_children(menuBar, map);

    return map;
  }
}
