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

  void populatePropertiesOfMenu(const QMenu *menu, QVariantMap &map)
  {
    map["name"] = menu->objectName();
    map["type"] = "menu";
    map["title"] = menu->title();

    QList<QVariant> list;
    foreach(const QAction *action, menu->actions())
      list<<extractMenus(action);
    map["children"] = list;
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
}
