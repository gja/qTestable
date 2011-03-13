#ifndef HELPER_H
#define HELPER_H

#include "common.h"
#include <QVariant>
#include "qjson/serializer.h"

namespace QTestable
{
  QVariantMap extractMenus(const QObject *object);
  QString serialize(const QVariant &variant);
}

#endif
