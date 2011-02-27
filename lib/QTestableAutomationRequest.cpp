#include "QTestableAutomationRequest.h"

#include <QRegExp>
#include <QStringList>
#include <QHash>

namespace QTestable 
{
  class QTestableAutomationRequestPrivate
  {
    void parseArguments()
    {
      QRegExp reg("([^=]*)=(.*)");
      QStringList pairs = arguments.split('&');

      foreach(QString string, pairs)
      {
        reg.indexIn(string);
        argumentMap.insert(reg.cap(1), reg.cap(2));
      }
    }

    public:
      bool isValid;
      QString targetClass;
      QString targetObject;
      QString command;
      QString arguments;
      QString originalRequest;
      QHash<QString, QString> argumentMap;

      QTestableAutomationRequestPrivate(const QString &request)
      {
        QRegExp reg("([^/]*)/([^/]*)/([^\\?]*)\\?\?([^\\?].*)?");
        isValid = reg.indexIn(request) != -1;
        originalRequest = request;

        targetClass = reg.cap(1);
        command = reg.cap(2);
        targetObject = reg.cap(3);
        arguments = reg.cap(4);
        parseArguments();
      }

      const QString &argument(const QString &key)
      {
        return argumentMap[key];
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

  QString QTestableAutomationRequest::argument(const QString &key) const
  {
    return d->argument(key);
  }
}
