#ifndef HANDLER_FOR_LABEL_H
#define HANDLER_FOR_LABEL_H

#include "../common.h"
#include "QTestableClassHandler.h"

#include <QLabel>

namespace QTestable
{
  class handler_for_label : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      handler_for_label(QString aHandlerName = "label") : QNamedClassHandler(aHandlerName) {}

    private slots:
      QString text(QObject *object, const QTestableAutomationRequest &request)
      {
        return ((QLabel *) object)->text();
      }
  };
}

#endif
