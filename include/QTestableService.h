#ifndef QTESTABLESERVICE_H
#define QTESTABLESERVICE_H

#include <QStringList>

class QTestableService
{
  static struct QTestableServicePrivate *d;

  public:

    // Recommended API. This will start the service if --enable-qTestable is found.
    static void startService(const QString &serviceName, const QStringList &arguments);
    static void startService(const QString &serviceName, bool isEnabled = true);
};

#endif
