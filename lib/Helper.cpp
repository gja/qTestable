#include "Helper.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

namespace QTestable
{
  void extractMenusFromAction(const QAction *action, QVariantMap &map)
  {
    if(action == NULL)
      return;

    map["text"] = action->text();
    map["type"] = "action";
  }

  void extractChildren(const QObject *menu, QVariantMap &map)
  {
    QList<QVariant> childrenMap;
    foreach(QObject *child, menu->children())
      childrenMap<<Helper::extractMenus(child);
    map["children"] = childrenMap;
  }

  void extractMenusFromMenu(const QMenu *menu, QVariantMap &map)
  {
    if(menu == NULL)
      return;

    map["title"] = menu->title();
    map["type"] = "menu";

    extractChildren(menu, map);
  }

  void extractMenusFromMenuBar(const QMenuBar *menu, QVariantMap &map)
  {
    if(menu == NULL)
      return;

    map["type"] = "menuBar";

    extractChildren(menu, map);
  }

  QVariantMap Helper::extractMenus(const QObject *object)
  {
    QVariantMap map;
    map["name"] = object->objectName();

    extractMenusFromAction(dynamic_cast<const QAction *>(object), map);
    extractMenusFromMenu(dynamic_cast<const QMenu *>(object), map);
    extractMenusFromMenuBar(dynamic_cast<const QMenuBar *>(object), map);
    return map;
  }
}
