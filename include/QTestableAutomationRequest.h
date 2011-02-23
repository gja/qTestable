#ifndef QTESTABLEAUTOMATIONREQUEST_H
#define QTESTABLEAUTOMATIONREQUEST_H

#include <QString>

namespace QTestable
{
  class QTestableAutomationRequest
  {
    public:
      QTestableAutomationRequest(const QString &requestURL);
      bool isValid;
      QString targetClass;
      QString targetObject;
      QString command;
      QString arguments;
      QString originalRequest;
  };
}

#endif
