#ifndef HELPER_H
#define HELPER_H

#include "common.h"
#include <QVariant>

namespace QTestable
{
  class Helper
  {
    public:
      static QVariantMap extractMenus(const QObject *object);
  };
}

#endif
