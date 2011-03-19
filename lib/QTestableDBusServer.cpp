#include "QTestableDBusServer.h"
#include "Dispatcher.h"

namespace QTestable 
{
  QTestableDBusServer::QTestableDBusServer(Dispatcher *dispatcher)
  {
    this->dispatcher = dispatcher;
  }

  QString QTestableDBusServer::Automate(const QString &request)
  {
    return dispatcher->handleRequest(request);
  }

  QStringList QTestableDBusServer::RegisteredObjects()
  {
    return dispatcher->registeredObjects();
  }

  QStringList QTestableDBusServer::RegisteredClasses()
  {
    return dispatcher->registeredClasses();
  }

  bool QTestableDBusServer::IsEnabled()
  {
    return true;
  }

  void QTestableDBusServer::doBroadcast(const QString &message)
  {
    emit Broadcast(message);
  }

  void QTestableDBusServer::doStarting()
  {
    emit Starting();
  }
}
