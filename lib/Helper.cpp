#include "Helper.h"
#include <QAction>

namespace QTestable
{
  QVariantMap Helper::extractMenus(const QObject *object)
  {
    QVariantMap map;
    map["name"] = object->objectName();

    const QAction *action = dynamic_cast<const QAction *>(object);
    map["text"] = action->text();
    return map;
  }
}
