#ifndef QTESTABLEAUTOMATIONREQUEST_H
#define QTESTABLEAUTOMATIONREQUEST_H

#include <QString>

namespace QTestable
{
  struct QTestableAutomationRequestPrivate;

  class QTestableAutomationRequest
  {
    QTestableAutomationRequestPrivate *d;

    public:
      QTestableAutomationRequest(const QString &requestURL);
      ~QTestableAutomationRequest();

      bool isValid() const;
      QString targetClass() const;
      QString targetObject() const;
      QString command() const;
      QString arguments() const;
      QString originalRequest() const;

      void setErrorMessage(const QString &errorMessage);
      QString errorMessage() const;

      QString argument(const QString &key) const;
  };
}

#endif
