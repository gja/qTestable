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
    ActiveQTestableApplicationPrivate()
    {
      server = new QTestableDBusServer();
      adapter = new QTestableDBusAdaptor(server);

      QDBusConnection connection = QDBusConnection::sessionBus();
      connection.registerService("org.qTestable");
      connection.registerObject("/", server);
    }
};

class DisabledQTestableApplicationPrivate : public QTestableApplicationPrivate
{
};

QTestableApplication::QTestableApplication(bool isEnabled)
{  
  d = isEnabled ? (QTestableApplicationPrivate *) new ActiveQTestableApplicationPrivate() : new DisabledQTestableApplicationPrivate();
}

QTestableApplication::QTestableApplication(const QStringList &arguments)
{
  ConfigParser parser(arguments);
  QTestableApplication(parser.isEnabled);
}

QTestableApplication::~QTestableApplication()
{
  delete d;
}
