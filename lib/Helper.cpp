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

  QVariant extractChildrenTree(const QObject *object)
  {
    QVariantMap map;
    map["name"] = object->objectName();
    if(object->children().count())
      extractChildren(object, map, extractChildrenTree);
    return map;
  }
}
