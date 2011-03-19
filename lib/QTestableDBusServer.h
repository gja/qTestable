#ifndef QTESTABLEDBUSSERVER_H
#define QTESTABLEDBUSSERVER_H

#include "common.h"

namespace QTestable 
{
  struct Dispatcher;

  class QTestableDBusServer : public QObject
  {
    Q_OBJECT

    Dispatcher *dispatcher;

    public:
      QTestableDBusServer(Dispatcher *dispatcher);
      void doBroadcast(const QString &message);
      void doStarting();

    public slots:
      QString Automate(const QString &request);
      QStringList RegisteredClasses();
      QStringList RegisteredObjects();
      bool IsEnabled();

    signals:
      void Broadcast(const QString &message);
      void Starting();
  };
}

#endif
