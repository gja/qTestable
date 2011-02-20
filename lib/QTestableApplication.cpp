#include "QTestableApplication.h"
#include "ConfigParser.h"
#include "QTestableDBusAdaptor.h"
#include "QTestableDBusServer.h"

#include <QDBusConnection>

class QTestableApplicationPrivate
{
  friend class QTestableApplication;
};

class ActiveQTestableApplicationPrivate : public QTestableApplicationPrivate
{
  QTestableDBusAdaptor *adapter;
  QTestableDBusServer *server;

  public:
    ActiveQTestableApplicationPrivate(const QString &serviceName)
    {
      server = new QTestableDBusServer();
      adapter = new QTestableDBusAdaptor(server);

      QDBusConnection connection = QDBusConnection::sessionBus();
      connection.registerService(serviceName);
      connection.registerObject("/", server);
    }
};

class DisabledQTestableApplicationPrivate : public QTestableApplicationPrivate
{
};

QTestableApplication::QTestableApplication(const QString &serviceName, bool isEnabled)
{  
  d = isEnabled ? (QTestableApplicationPrivate *) new ActiveQTestableApplicationPrivate(serviceName) : new DisabledQTestableApplicationPrivate();
}

QTestableApplication::QTestableApplication(const QString &serviceName, const QStringList &arguments)
{
  ConfigParser parser(arguments);
  QTestableApplication(serviceName, parser.isEnabled);
}
