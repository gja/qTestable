#ifndef QTESTABLESERVICE_H
#define QTESTABLESERVICE_H

#include <QStringList>
struct QTestableClassHandler;

class QTestableService
{
  static struct QTestableServicePrivate *d;

  public:

    // Recommended API. This will start the service if --enable-qTestable is found.
    static void startService(const QString &serviceName, const QStringList &arguments);
    static void startService(const QString &serviceName, bool isEnabled = true);

    static void registerClass(const QString &className, QTestableClassHandler *handler);
    static void registerInvalidRequestHandler(QTestableClassHandler *handler);
    static void registerObject(const QString &objectName, QObject *handler);
};

#endif
