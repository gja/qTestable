#include "QTestableDBusServer.h"
#include "Dispatcher.h"

QTestableDBusServer::QTestableDBusServer(Dispatcher *dispatcher)
{
  this->dispatcher = dispatcher;
}

QString QTestableDBusServer::Automate(const QString &request)
{
  return dispatcher->handleRequest(request);
}
