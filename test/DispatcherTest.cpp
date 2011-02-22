#include <QTest>
#include "Dispatcher.h"
#include "QTestableClassHandler.h"

class ReturnNameHandler : public QTestableClassHandler
{
  QString name;
  public:
    ReturnNameHandler(const QString &aName) : name(aName) { }
    virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request)
    {
      return name;
    }
};

class ObjectWithName : public QObject
{
  QString name;
  public:
    ObjectWithName(const QString &aName) : name(aName) { }
    virtual QString getName()
    {
      return name;
    }
};

class ReturnObjectNameHandler : public QTestableClassHandler
{
    virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request)
    {
      if (object == NULL) return "null";
      return ((ObjectWithName *) object)->getName();      
    }
};


class DispatcherTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBeAbleToRegisterAndDispatchToDifferentClassHandlers()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnNameHandler("class1"));
      dispatcher.registerClass("class2", new ReturnNameHandler("class2"));      

      QCOMPARE(dispatcher.handleRequest("class1/button1/click"), QString("class1"));
      QCOMPARE(dispatcher.handleRequest("class2/button1/click"), QString("class2"));
      QCOMPARE(dispatcher.handleRequest("invalid"), QString(""));
    }

    void shouldBeAbleToUnregisterAClass()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnNameHandler("class1"));
      dispatcher.unRegisterClass("class1");      

      QCOMPARE(dispatcher.handleRequest("class1/button1/click"), QString(""));
    }

    void shouldBeAbleToRegisterAnInvalidRequestHandler()
    {
      Dispatcher dispatcher;
      dispatcher.setInvalidRequestHandler(new ReturnNameHandler("invalid"));

      QCOMPARE(dispatcher.handleRequest("class1/button1/click"), QString("invalid"));
      QCOMPARE(dispatcher.handleRequest("class2/button1/click"), QString("invalid"));
      QCOMPARE(dispatcher.handleRequest("invalid"), QString("invalid"));
    }

    void shouldBeAbleToRegisterObjects()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnObjectNameHandler());
      dispatcher.registerObject("button1", new ObjectWithName("button1"));
      dispatcher.registerObject("button2", new ObjectWithName("button2"));

      QCOMPARE(dispatcher.handleRequest("class1/button1/click"), QString("button1"));
      QCOMPARE(dispatcher.handleRequest("class1/button2/click"), QString("button2"));
    }

    void shouldBeAbleToUnregisterAnObject()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnObjectNameHandler());
      dispatcher.registerObject("button1", new ObjectWithName("button1"));
      dispatcher.unRegisterObject("button1");

      QCOMPARE(dispatcher.handleRequest("class1/button1/click"), QString("null"));
    }
};

QTEST_MAIN(DispatcherTest)
#include "DispatcherTest.moc"
