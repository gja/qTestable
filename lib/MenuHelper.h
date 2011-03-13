#ifndef MENUHELPER_H
#define MENUHELPER_H

#include "common.h"
#include <QVariant>
#include <QMenuBar>
#include <QAction>

namespace QTestable
{
  QVariant extractMenus(const QAction *object);
  QVariant extractMenus(const QMenuBar *bar);
}

#endif
