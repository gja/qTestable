#include <QTest>
#include "ParseRestRequest.h"

class ParseRestRequestTest : public QObject
{
  Q_OBJECT
  private slots:
    void ShouldBeAbleToParseRestRequest_data()
    {
      QTest::addColumn<QString>("request");
      QTest::addColumn<bool>("isValid");
      QTest::addColumn<QString>("targetClass");
      QTest::addColumn<QString>("targetObject");
      QTest::addColumn<QString>("command");
      QTest::addColumn<QString>("arguments");

      QTest::newRow("An Empty Request")<<""<<false<<""<<""<<""<<"";
      QTest::newRow("An Request Without Arguments")<<"button/myButton/click"<<true<<"button"<<"myButton"<<"click"<<"";
      QTest::newRow("An Request With Arguments")<<"button/myButton/click/foo"<<true<<"button"<<"myButton"<<"click"<<"foo";
      QTest::newRow("An Request With Arguments with /")<<"button/myButton/click/foo/bar"<<true<<"button"<<"myButton"<<"click"<<"foo/bar";
    }

    void ShouldBeAbleToParseRestRequest()
    {
      QFETCH(QString, request);
      QFETCH(bool, isValid);
      QFETCH(QString, targetClass);
      QFETCH(QString, targetObject);
      QFETCH(QString, command);
      QFETCH(QString, arguments);

      ParseRestRequest parser(request);

      QCOMPARE(isValid, parser.isValid);
      QCOMPARE(targetClass, parser.targetClass);
      QCOMPARE(targetObject, parser.targetObject);
      QCOMPARE(command, parser.command);
      QCOMPARE(arguments, parser.arguments);
    }
};

QTEST_MAIN(ParseRestRequestTest)
#include "ParseRestRequestTest.moc"
