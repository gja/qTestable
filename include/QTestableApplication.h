#ifndef QTESTABLEAPPLICATION_H
#define QTESTABLEAPPLICATION_H

#include <QStringList>

class QTestableApplication
{
  struct QTestableApplicationPrivate *d;

  public:
    QTestableApplication(const QStringList &arguments);
    QTestableApplication(bool isEnabled = true);
    ~QTestableApplication();
};

#endif
