#include "QTestableClassHandler.h"

QString QTestableClassHandler::handleRequest(QObject *object, const QTestableAutomationRequest &request)
{
  if (!request.isValid)
    return handleInvalidRequest(object, request);

  QString ret;
  QByteArray ba = request.command.toLatin1(); // do not inline this, as it can cause memory leak
  if(QMetaObject::invokeMethod(this, ba.constData(), Qt::DirectConnection, Q_RETURN_ARG(QString, ret), Q_ARG(QObject *, object), Q_ARG(const QTestableAutomationRequest &, request)))
    return ret;
  else
    return handleInvalidRequest(object, request);
}
