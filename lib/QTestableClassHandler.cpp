#include "QTestableClassHandler.h"
#include "qjson/serializer.h"

#include <QVariant>

namespace QTestable 
{
  QString QTestableClassHandler::handleRequest(QObject *object, const QTestableAutomationRequest &request)
  {
    if (!request.isValid() || object == NULL)
      return request.errorMessage();

    QString ret;
    QByteArray ba = request.command().toLatin1(); // do not inline this, as it can cause memory leak
    if(QMetaObject::invokeMethod(this, ba.constData(), Qt::DirectConnection, Q_RETURN_ARG(QString, ret), Q_ARG(QObject *, object), Q_ARG(const QTestableAutomationRequest &, request)))
      return ret;
    else
      return handleInvalidRequest(object, request);
  }

  QNamedClassHandler::QNamedClassHandler(QString aHandlerName) : name(aHandlerName)
  {}

  QString QNamedClassHandler::handleInvalidRequest(QObject *object, const QTestableAutomationRequest &request)
  {
    QVariantMap variant;
    variant["error"] = QString("Error: Unable To Execute Command '%1' in Handler '%2'").arg(request.command()).arg(name);
    variant["targetObject"] = request.targetObject();
    variant["targetClass"] = request.targetClass();
    variant["arguments"] = request.arguments();
    return QJson::Serializer().serialize(variant);
  }
}
