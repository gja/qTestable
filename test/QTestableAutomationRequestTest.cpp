#include <QTest>
#include "QTestableAutomationRequest.h"

using namespace QTestable;

class QTestableAutomationRequestTest : public QObject
{
  Q_OBJECT
  private slots:
    void ShouldBeAbleToParseARequestWithoutArguments_data()
    {
      QTest::addColumn<QString>("request");
      QTest::addColumn<bool>("isValid");
      QTest::addColumn<QString>("targetClass");
      QTest::addColumn<QString>("targetObject");
      QTest::addColumn<QString>("command");

      QTest::newRow("An Empty Request")<<""<<false<<""<<""<<"";
      QTest::newRow("An Request Without Arguments")<<"button/click/myButton"<<true<<"button"<<"myButton"<<"click";
      QTest::newRow("An Request Child In The Target")<<"button/click/myButton/child"<<true<<"button"<<"myButton/child"<<"click";
      QTest::newRow("An Request With Arguments To be ignored")<<"button/click/myButton?foo=bar"<<true<<"button"<<"myButton"<<"click";
    }

    void ShouldBeAbleToParseARequestWithoutArguments()
    {
      QFETCH(QString, request);
      QFETCH(bool, isValid);
      QFETCH(QString, targetClass);
      QFETCH(QString, targetObject);
      QFETCH(QString, command);

      QTestableAutomationRequest parser(request);

      QCOMPARE(isValid, parser.isValid());
      QCOMPARE(targetClass, parser.targetClass());
      QCOMPARE(targetObject, parser.targetObject());
      QCOMPARE(command, parser.command());
      QCOMPARE(request, parser.originalRequest());
    }

    void ShouldBeAbleToParseARequestWithArguments()
    {
      QTestableAutomationRequest request("foo/bar/baz?q1=a1&q2=a2");
//      QCOMPARE("a1", request.argument("q1"));
    }
};

QTEST_MAIN(QTestableAutomationRequestTest)
#include "QTestableAutomationRequestTest.moc"
