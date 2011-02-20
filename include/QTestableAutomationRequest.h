#ifndef QTESTABLEAUTOMATIONREQUEST_H
#define QTESTABLEAUTOMATIONREQUEST_H

#include <QString>

class QTestableAutomationRequest
{
  public:
    QTestableAutomationRequest(const QString &requestURL);
    bool isValid;
    QString targetClass;
    QString targetObject;
    QString command;
    QString arguments;
};

#endif
