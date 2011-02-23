#ifndef QTESTABLECLASSHANDLER_H
#define QTESTABLECLASSHANDLER_H

#include "IQTestableClassHandler.h"
namespace QTestable 
{
  class QTestableClassHandler : public IQTestableClassHandler
  {
    public:
      virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request);
      virtual QString handleInvalidRequest(QObject *object, const QTestableAutomationRequest &request) = 0;

    private slots:
      // Declare all your commands here, ex:
      // QString foo(Object *foo, const QTestableAutomationRequest &request)
  };
}

#endif
