#ifndef HELPER_H
#define HELPER_H

#include "common.h"
#include "qjson/serializer.h"

namespace QTestable
{
  QVariant extractChildrenTree(const QObject *object);
  QString serialize(const QVariant &variant);
}

#endif
