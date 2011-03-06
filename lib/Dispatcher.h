#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "common.h"
#include "IQTestableClassHandler.h"
#include "ObjectFinder.h"

namespace QTestable 
{
  class Dispatcher
  {
    QHash<QString, IQTestableClassHandler *> classMap;
    ObjectFinder objectMap;
    IQTestableClassHandler *invalidRequestHandler;

    public:
      void registerClass(const QString &className, IQTestableClassHandler *handler);
      void unRegisterClass(const QString &className);
      void registerObject(const QString &objectName, QObject *object);
      void unRegisterObject(const QString &objectName);
      void setInvalidRequestHandler(IQTestableClassHandler *handler);

      QString handleRequest(const QString &request);
      QStringList registeredObjects();
      QStringList registeredClasses();

      Dispatcher();
  };
}

#endif
