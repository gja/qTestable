#ifndef QTESTABLEAPPLICATION_H
#define QTESTABLEAPPLICATION_H

#include <QStringList>

class QTestableApplication
{
  struct QTestableApplicationPrivate *d;

  public:
    QTestableApplication(const QString &serviceName, const QStringList &arguments); // Recommended API, enabled if --enable-qTestable
    QTestableApplication(const QString &serviceName, bool isEnabled = true);
    ~QTestableApplication();
};

#endif
