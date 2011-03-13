#include "Helper.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

namespace QTestable
{
  QString serialize(const QVariant &variant)
  {
    return QJson::Serializer().serialize(variant);
  }

  void extractChildren(const QObject *parent, QVariantMap &map, QVariant (*mapping)(const QObject*))
  {
    QList<QVariant> childrenMap;
    foreach(QObject *child, parent->children())
      childrenMap<<mapping(child);
    map["children"] = childrenMap;
  }

  void extractMenusFromAction(const QAction *action, QVariantMap &map)
  {
    if(action == NULL)
      return;

    map["text"] = action->text();
    map["type"] = "action";
  }

  void extractMenusFromMenu(const QMenu *menu, QVariantMap &map)
  {
    if(menu == NULL)
      return;

    map["title"] = menu->title();
    map["type"] = "menu";

    extractChildren(menu, map, extractMenus);
  }

  void extractMenusFromMenuBar(const QMenuBar *menu, QVariantMap &map)
  {
    if(menu == NULL)
      return;

    map["type"] = "menuBar";

    extractChildren(menu, map, extractMenus);
  }

  QVariant extractMenus(const QObject *object)
  {
    QVariantMap map;
    map["name"] = object->objectName();

    extractMenusFromAction(dynamic_cast<const QAction *>(object), map);
    extractMenusFromMenu(dynamic_cast<const QMenu *>(object), map);
    extractMenusFromMenuBar(dynamic_cast<const QMenuBar *>(object), map);
    return map;
  }

  QVariant extractChildrenTree(const QObject *object)
  {
    QVariantMap map;
    map["name"] = object->objectName();
    if(object->children().count())
      extractChildren(object, map, extractChildrenTree);
    return map;
  }
}
