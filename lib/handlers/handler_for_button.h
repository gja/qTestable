#ifndef HANDLER_FOR_BUTTON_H
#define HANDLER_FOR_BUTTON_H

#include "../common.h"
#include "QTestableClassHandler.h"
#include <QAbstractButton>

namespace QTestable
{
  class handler_for_button : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      handler_for_button(QString aHandlerName = "button") : QNamedClassHandler(aHandlerName) {}

    private slots:
       QString click(QObject *object, const QTestableAutomationRequest &request)
       {
         ((QAbstractButton*) object)->click();
         return "";
       }

       QString text(QObject *object, const QTestableAutomationRequest &request)
       {
         return ((QAbstractButton*) object)->text();
       }
  };
}

#endif
