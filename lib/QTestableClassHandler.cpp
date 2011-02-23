#include "QTestableClassHandler.h"

namespace QTestable 
{
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

  QNamedClassHandler::QNamedClassHandler(QString aHandlerName) : name(aHandlerName)
  {}

  QString QNamedClassHandler::handleInvalidRequest(QObject *object, const QTestableAutomationRequest &request)
  {
    return QString("Error: Unable To Execute Command '%1' in Handler '%2'. request = { targetObject = '%3', targetClass = '%4', arguments = '%5' }").
                               arg(request.command).arg(name).arg(request.targetObject).arg(request.targetClass).arg(request.arguments);
  }
}
