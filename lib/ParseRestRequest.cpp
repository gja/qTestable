#include "ParseRestRequest.h"

#include <QRegExp>

ParseRestRequest::ParseRestRequest(const QString &request)
{
  QRegExp reg("([^/]*)/([^/]*)/(.*)");
  QRegExp getCommand("([^/]*)/(.*)");

  isValid = reg.indexIn(request) != -1;

  if(isValid)
  {
    targetClass = reg.cap(1);
    targetObject = reg.cap(2);
    QString commandWithArgs = reg.cap(3);

    if(getCommand.indexIn(commandWithArgs) == -1)
      command = commandWithArgs;
    else {
      command = getCommand.cap(1);
      arguments = getCommand.cap(2);
    }
  }
}
