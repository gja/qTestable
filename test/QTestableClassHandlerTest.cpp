#include <QTest>
#include "QTestableClassHandler.h"
#include "Dispatcher.h"

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
      QCOMPARE(dispatcher.handleRequest("dummy/obj/foo"), QString("foo"));
    }

    void shouldBeAbleToProvideACallbackForAnInvalidRequest()
    {
      Dispatcher dispatcher;
      dispatcher.setInvalidRequestHandler(new DummyHandler());
      QCOMPARE(dispatcher.handleRequest("dummy"), QString("invalid"));
    }

    void shouldBeAbleToProvideACallbackForANonExistantCommand()
    {
      Dispatcher dispatcher;
      dispatcher.setInvalidRequestHandler(new DummyHandler());
      QCOMPARE(dispatcher.handleRequest("dummy/obj/uaohtneunah"), QString("invalid"));
    }
};

QTEST_MAIN(QTestableClassHandlerTest)
#include "QTestableClassHandlerTest.moc"
