#include "QTestableAutomationRequest.h"

#include <QRegExp>

namespace QTestable 
{
  QTestableAutomationRequest::QTestableAutomationRequest(const QString &request)
  {
    QRegExp reg("([^/]*)/([^/]*)/([^\\?]*)\\?\?(.*)");

    isValid = reg.indexIn(request) != -1;
    originalRequest = request;

    targetClass = reg.cap(1);
    command = reg.cap(2);
    targetObject = reg.cap(3);
  }
}
