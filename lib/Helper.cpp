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

  QVariant extractChildrenTree(const QObject *object)
  {
    QVariantMap map;
    map["name"] = object->objectName();
    if(object->children().count())
      extractChildren(object, map, extractChildrenTree);
    return map;
  }
}
