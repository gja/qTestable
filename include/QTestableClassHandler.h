#ifndef QTESTABLECLASSHANDLER_H
#define QTESTABLECLASSHANDLER_H

#include <QObject>
#include <QString>

#include "QTestableAutomationRequest.h"

class QTestableClassHandler
{
  public:
    virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request) = 0;
};

#endif
