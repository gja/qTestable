#ifndef QTESTABLEDBUSSERVER_H
#define QTESTABLEDBUSSERVER_H

#include "common.h"

struct Dispatcher;

class QTestableDBusServer : public QObject
{
  Q_OBJECT

  Dispatcher *dispatcher;

  public:
    QTestableDBusServer(Dispatcher *dispatcher);

  public slots:
    QString Automate(const QString &request);
    QStringList RegisteredClasses();
    QStringList RegisteredObjects();
    bool IsEnabled();
};

#endif
