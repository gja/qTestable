#include "QTestableService.h"
#include "ConfigParser.h"
#include "QTestableDBusAdaptor.h"
#include "QTestableDBusServer.h"

#include <QDBusConnection>

class QTestableServicePrivate
{
  friend class QTestableService;
};

class ActiveQTestableServicePrivate : public QTestableServicePrivate
{
  QTestableDBusAdaptor *adapter;
  QTestableDBusServer *server;

  public:
    ActiveQTestableServicePrivate(const QString &serviceName)
    {
      server = new QTestableDBusServer();
      adapter = new QTestableDBusAdaptor(server);

      QDBusConnection connection = QDBusConnection::sessionBus();
      connection.registerService(serviceName);
      connection.registerObject("/", server);
    }
};

class DisabledQTestableServicePrivate : public QTestableServicePrivate
{
};

QTestableServicePrivate *QTestableService::d;
void QTestableService::startService(const QString &serviceName, bool isEnabled)
{  
  d = isEnabled ? (QTestableServicePrivate *) new ActiveQTestableServicePrivate(serviceName) : new DisabledQTestableServicePrivate();
}

void QTestableService::startService(const QString &serviceName, const QStringList &arguments)
{
  ConfigParser parser(arguments);
  startService(serviceName, parser.isEnabled);
}
