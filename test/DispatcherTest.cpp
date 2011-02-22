#include <QTest>
#include "Dispatcher.h"
#include "IQTestableClassHandler.h"

class ReturnNameHandler : public IQTestableClassHandler
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

class ReturnObjectNameHandler : public IQTestableClassHandler
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

      QCOMPARE(dispatcher.handleRequest("class1/click/button1"), QString("class1"));
      QCOMPARE(dispatcher.handleRequest("class2/click/button2"), QString("class2"));
      QCOMPARE(dispatcher.handleRequest("invalid"), QString(""));
    }

    void shouldBeAbleToUnregisterAClass()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnNameHandler("class1"));
      dispatcher.unRegisterClass("class1");      

      QCOMPARE(dispatcher.handleRequest("class1/click/button1"), QString(""));
    }

    void shouldBeAbleToRegisterAnInvalidRequestHandler()
    {
      Dispatcher dispatcher;
      dispatcher.setInvalidRequestHandler(new ReturnNameHandler("invalid"));

      QCOMPARE(dispatcher.handleRequest("class1/click/button1"), QString("invalid"));
      QCOMPARE(dispatcher.handleRequest("class2/click/button1"), QString("invalid"));
      QCOMPARE(dispatcher.handleRequest("invalid"), QString("invalid"));
    }

    void shouldBeAbleToRegisterObjects()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnObjectNameHandler());
      dispatcher.registerObject("button1", new ObjectWithName("button1"));
      dispatcher.registerObject("button2", new ObjectWithName("button2"));

      QCOMPARE(dispatcher.handleRequest("class1/click/button1"), QString("button1"));
      QCOMPARE(dispatcher.handleRequest("class1/click/button2"), QString("button2"));
    }

    void shouldBeAbleToUnregisterAnObject()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnObjectNameHandler());
      dispatcher.registerObject("button1", new ObjectWithName("button1"));
      dispatcher.unRegisterObject("button1");

      QCOMPARE(dispatcher.handleRequest("class1/click/button1"), QString("null"));
    }

    void shouldBeAbleToGetListOfRegisteredObjectsAndClasses()
    {
      Dispatcher dispatcher;
      dispatcher.registerClass("class1", new ReturnObjectNameHandler());
      dispatcher.registerObject("button1", new ObjectWithName("button1"));

      QCOMPARE(dispatcher.registeredObjects().size(), 1);
      QCOMPARE(dispatcher.registeredClasses().size(), 1);
    }
};

QTEST_MAIN(DispatcherTest)
#include "DispatcherTest.moc"
