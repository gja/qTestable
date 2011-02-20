#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "common.h"
#include "QTestableClassHandler.h"

class Dispatcher
{
  QHash<QString, QTestableClassHandler *> classMap;
  QHash<QString, QObject *> objectMap;
  QTestableClassHandler *invalidRequestHandler;

  public:
    void registerClass(const QString &className, QTestableClassHandler *handler);
    void registerObject(const QString &objectName, QObject *object);
    void setInvalidRequestHandler(QTestableClassHandler *handler);
    QString handleRequest(const QString &request);

    Dispatcher();
};

#endif
