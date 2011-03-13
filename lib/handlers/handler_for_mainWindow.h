#ifndef HANDLER_FOR_MAINWINDOW_H
#define HANDLER_FOR_MAINWINDOW_H

#include "../common.h"
#include "QTestableClassHandler.h"
#include "qjson/serializer.h"

#include "../MenuHelper.h"
#include <QMainWindow>

namespace QTestable
{
  class handler_for_mainWindow : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      handler_for_mainWindow(QString aHandlerName = "mainWindow") : QNamedClassHandler(aHandlerName) {}

    private slots:
      QString getMenus(QObject *object, const QTestableAutomationRequest &request)
      {
        return serialize(extractMenus(((QMainWindow *) object)->menuBar()));
      }
  };
}

#endif
