#include "QTestableAutomationRequest.h"

#include <QRegExp>

QTestableAutomationRequest::QTestableAutomationRequest(const QString &request)
{
  QRegExp reg("([^/]*)/([^/]*)/(.*)");
  QRegExp getCommand("([^/]*)/(.*)");

  isValid = reg.indexIn(request) != -1;
  originalRequest = request;

  if(isValid)
  {
    targetClass = reg.cap(1);
    command = reg.cap(2);
    QString objectWithArgs = reg.cap(3);

    if(getCommand.indexIn(objectWithArgs) == -1)
      targetObject = objectWithArgs;
    else {
      targetObject = getCommand.cap(1);
      arguments = getCommand.cap(2);
    }
  }
}
