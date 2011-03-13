#ifndef HELPER_H
#define HELPER_H

#include "common.h"
#include <QVariant>
#include "qjson/serializer.h"

struct QAction;

namespace QTestable
{
  QVariant extractMenus(const QAction *object);
  QVariant extractChildrenTree(const QObject *object);
  QString serialize(const QVariant &variant);
}

#endif
