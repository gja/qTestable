#ifndef HANDLER_FOR_MENUBAR_H
#define HANDLER_FOR_MENUBAR_H

#include "../common.h"
#include "QTestableClassHandler.h"

#include <QMenuBar>

namespace QTestable
{
  class handler_for_menuBar : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      handler_for_menuBar(QString aHandlerName = "menuBar") : QNamedClassHandler(aHandlerName) {}

    private slots:
      QString getTopLevelMenus(QObject *object, const QTestableAutomationRequest &request)
      {
        QMenuBar *menuBar = (QMenuBar *) object;
        return "foo";
      }
  };
}

#endif
