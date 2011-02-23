#ifndef HANDLER_FOR_APPLICATION_H
#define HANDLER_FOR_APPLICATION_H

#include "../common.h"
#include "QTestableClassHandler.h"
#include <QApplication>

namespace QTestable
{
  class handler_for_application : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      handler_for_application(QString aHandlerName = "application") : QNamedClassHandler(aHandlerName) {}

    private slots:
      QString quit(QObject *object, const QTestableAutomationRequest &request)
      {
        ((QApplication *) object)->quit();
        return "";
      }
  };
}

#endif
