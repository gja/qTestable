#ifndef HANDLER_FOR_MENU_H
#define HANDLER_FOR_MENU_H

#include "../common.h"
#include "../MenuHelper.h"
#include "QTestableClassHandler.h"

#include <QMenu>

namespace QTestable
{
  class handler_for_menu : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      handler_for_menu(QString aHandlerName = "menu") : QNamedClassHandler(aHandlerName) {}

    private slots:
      QString getMenus(QObject *object, const QTestableAutomationRequest &request)
      {
        return serialize(extractMenus(((QMenu *) object)->menuAction()));
      }
  };  
}

#endif
