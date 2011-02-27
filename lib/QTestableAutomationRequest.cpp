#include "QTestableAutomationRequest.h"

#include <QRegExp>

namespace QTestable 
{
  class QTestableAutomationRequestPrivate
  {
    public:
      bool isValid;
      QString targetClass;
      QString targetObject;
      QString command;
      QString arguments;
      QString originalRequest;

      QTestableAutomationRequestPrivate(const QString &request)
      {
        QRegExp reg("([^/]*)/([^/]*)/([^\\?]*)\\?\?(.*)");
        isValid = reg.indexIn(request) != -1;
        originalRequest = request;

        targetClass = reg.cap(1);
        command = reg.cap(2);
        targetObject = reg.cap(3);
      }
  };

  QTestableAutomationRequest::QTestableAutomationRequest(const QString &request)
  {
    d = new QTestableAutomationRequestPrivate(request);
  }

  QTestableAutomationRequest::~QTestableAutomationRequest()
  {
    delete d;
  }

  bool QTestableAutomationRequest::isValid() const
  {
    return d->isValid;
  }

  QString QTestableAutomationRequest::command() const
  {
    return d->command;
  }

  QString QTestableAutomationRequest::targetObject() const
  {
    return d->targetObject;
  }

  QString QTestableAutomationRequest::targetClass() const
  {
    return d->targetClass;
  }

  QString QTestableAutomationRequest::arguments() const
  {
    return d->arguments;
  }

  QString QTestableAutomationRequest::originalRequest() const
  {
    return d->originalRequest;
  }
}
