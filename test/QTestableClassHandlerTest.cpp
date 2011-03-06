#include <QTest>
#include "QTestableClassHandler.h"
#include "Dispatcher.h"

using namespace QTestable;

class DummyHandler : public QTestableClassHandler
{
  Q_OBJECT

  public:
    virtual QString handleInvalidRequest(QObject *object, const QTestableAutomationRequest &request)
    {
      return "invalid";
    }

  private slots:
    QString foo(QObject *object, const QTestableAutomationRequest &request)
    {
      return "foo";
    }
};

class QTestableClassHandlerTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBeAbleToRegisterACallBack()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("dummy", new DummyHandler());
      dispatcher.registerObject("obj", new QObject());
      QCOMPARE(dispatcher.handleRequest("dummy/foo/obj"), QString("foo"));
    }

    void shouldBeAbleToHandleAnInvalidRequest()
    {
      Dispatcher dispatcher;
      dispatcher.setInvalidRequestHandler(new DummyHandler());
      QCOMPARE(dispatcher.handleRequest("dummy"), QString("Invalid Request"));
    }

    void shouldBeAbleToProvideACallbackForANonExistantCommand()
    {
      Dispatcher dispatcher;
      dispatcher.setInvalidRequestHandler(new DummyHandler());
      dispatcher.registerObject("obj", new QObject());
      QCOMPARE(dispatcher.handleRequest("dummy/uaohtneunah/obj"), QString("invalid"));
    }
    
    void shouldHaveADefaultHandlerForNonExistingCommand()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("dummy", new QNamedClassHandler("name"));
      dispatcher.registerObject("obj", new QObject());
      QCOMPARE(dispatcher.handleRequest("dummy/foo/obj"), QString("Error: Unable To Execute Command 'foo' in Handler 'name'. request = { targetObject = 'obj', targetClass = 'dummy', arguments = '' }"));
    }
};

QTEST_MAIN(QTestableClassHandlerTest)
#include "QTestableClassHandlerTest.moc"
