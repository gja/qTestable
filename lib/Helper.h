#ifndef HELPER_H
#define HELPER_H

#include "common.h"
#include <QVariant>
#include "qjson/serializer.h"

namespace QTestable
{
  QVariant extractMenus(const QObject *object);
  QString serialize(const QVariant &variant);
  void extractChildren(const QObject *parent, QVariantMap &map, QVariant (*mapping)(const QObject*));
}

#endif
