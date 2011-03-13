#ifndef MENUHELPER_H
#define MENUHELPER_H

#include "common.h"
#include <QVariant>

struct QAction;

namespace QTestable
{
  QVariant extractMenus(const QAction *object);
}

#endif
