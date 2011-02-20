#ifndef QTESTABLEDBUSSERVER_H
#define QTESTABLEDBUSSERVER_H

#include "common.h"

class QTestableDBusServer : public QObject
{
  Q_OBJECT

  public slots:
    QString Automate(const QString &request);
};

#endif
