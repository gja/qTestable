#ifndef IQTESTABLECLASSHANDLER_H
#define IQTESTABLECLASSHANDLER_H

#include <QObject>
#include <QString>

#include "QTestableAutomationRequest.h"

class IQTestableClassHandler
{
  public:
    virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request) = 0;
};

#endif
