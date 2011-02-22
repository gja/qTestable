#include "Dispatcher.h"
#include "QTestableAutomationRequest.h"

class NullRequestHandler : public QTestableClassHandler
{
  public:
    virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request)
    {
      return "";
    }
};

Dispatcher::Dispatcher()
{
  setInvalidRequestHandler(new NullRequestHandler());
}

void Dispatcher::registerClass(const QString &className, QTestableClassHandler *handler)
{
  classMap.insert(className, handler);
}

void Dispatcher::unRegisterClass(const QString &className)
{
  classMap.remove(className);
}

void Dispatcher::registerObject(const QString &objectName, QObject *object)
{
  objectMap.insert(objectName, object);
}

void Dispatcher::unRegisterObject(const QString &objectName)
{
  objectMap.remove(objectName);
}

void Dispatcher::setInvalidRequestHandler(QTestableClassHandler *handler)
{
  invalidRequestHandler = handler;
}

QString Dispatcher::handleRequest(const QString &request)
{
  QTestableAutomationRequest req(request);
  if(! req.isValid)
    return invalidRequestHandler->handleRequest(NULL, req);

  QTestableClassHandler *handler = classMap[req.targetClass];
  if (handler == NULL)
    handler = invalidRequestHandler;

  return handler->handleRequest(objectMap[req.targetObject], req);
}

QStringList Dispatcher::registeredObjects()
{
  return objectMap.keys();
}

QStringList Dispatcher::registeredClasses()
{
  return classMap.keys();
}
