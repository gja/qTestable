#include "QTestableService.h"
#include "ConfigParser.h"
#include "QTestableDBusAdaptor.h"
#include "QTestableDBusServer.h"
#include "Dispatcher.h"
#include "StandardHandlers.h"

#include <QDBusConnection>

namespace QTestable 
{
  class QTestableServicePrivate
  {
    friend class QTestableService;
    public:
      virtual void registerClass(const QString &className, IQTestableClassHandler *handler) = 0;
      virtual void unRegisterClass(const QString &className) = 0;
      virtual void registerInvalidRequestHandler(IQTestableClassHandler *handler) = 0;
      virtual void registerObject(const QString &objectName, QObject *handler) = 0;
      virtual void unRegisterObject(const QString &objectName) = 0;
      virtual void registerStandardHandlers() = 0;
  };

  class ActiveQTestableServicePrivate : public QTestableServicePrivate
  {
    QTestableDBusAdaptor *adapter;
    QTestableDBusServer *server;
    Dispatcher dispatcher;

    public:
      ActiveQTestableServicePrivate(const QString &serviceName)
      {
        server = new QTestableDBusServer(&dispatcher);
        adapter = new QTestableDBusAdaptor(server);

        QDBusConnection connection = QDBusConnection::sessionBus();
        connection.registerService(serviceName);
        connection.registerObject("/", server);
      }

      virtual void registerClass(const QString &className, IQTestableClassHandler *handler) 
      {
        dispatcher.registerClass(className, handler);
      }

      virtual void unRegisterClass(const QString &className) 
      {
        dispatcher.unRegisterClass(className);
      }

      virtual void registerInvalidRequestHandler(IQTestableClassHandler *handler) 
      {
        dispatcher.setInvalidRequestHandler(handler);
      }

      virtual void registerObject(const QString &objectName, QObject *handler) 
      {
        dispatcher.registerObject(objectName, handler);
      }

      virtual void unRegisterObject(const QString &objectName) 
      {
        dispatcher.unRegisterObject(objectName);
      }

      virtual void registerStandardHandlers()
      {
        dispatcher.registerClass("button", StandardHandlers::buttonHandler());
        dispatcher.registerClass("application", StandardHandlers::applicationHandler());
        dispatcher.registerClass("label", StandardHandlers::labelHandler());
        dispatcher.registerClass("menuBar", StandardHandlers::menuBarHandler());
        //NEXTHANDLERHERE
      }
  };

  class DisabledQTestableServicePrivate : public QTestableServicePrivate
  {
      virtual void registerClass(const QString &className, IQTestableClassHandler *handler) {};
      virtual void unRegisterClass(const QString &className) {};
      virtual void registerInvalidRequestHandler(IQTestableClassHandler *handler) {};
      virtual void registerObject(const QString &objectName, QObject *handler) {};
      virtual void unRegisterObject(const QString &objectName) {};
      virtual void registerStandardHandlers() {}
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

  void QTestableService::registerClass(const QString &className, IQTestableClassHandler *handler)
  {
    d->registerClass(className, handler);
  }

  void QTestableService::unRegisterClass(const QString &className)
  {
    d->unRegisterClass(className);
  }

  void QTestableService::registerInvalidRequestHandler(IQTestableClassHandler *handler)
  {
    d->registerInvalidRequestHandler(handler);
  }

  void QTestableService::registerObject(const QString &objectName, QObject *handler)
  {
    d->registerObject(objectName, handler);
  }

  void QTestableService::unRegisterObject(const QString &objectName)
  {
    d->unRegisterObject(objectName);
  }

  void QTestableService::registerStandardHandlers()
  {
    d->registerStandardHandlers();
  }
}
