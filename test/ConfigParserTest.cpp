#include <QTest>
#include "ConfigParser.h"

class ConfigParserTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBeAbleToReadPort_data()
    {
      QTest::addColumn<QStringList>("arguments");
      QTest::addColumn<int>("port");
      QTest::addColumn<int>("finalSize");

      QTest::newRow("Empty List")<<QStringList()<<0<<0;
      QTest::newRow("Irrelevant Arguments")<<(QStringList()<<"foo"<<"bar"<<"baz")<<0<<3;
      QTest::newRow("invalid-noEquals")<<(QStringList()<<"foo"<<"--qTestable-port"<<"baz")<<0<<3;
      QTest::newRow("invalid-noValue")<<(QStringList()<<"foo"<<"--qTestable-port="<<"baz")<<0<<3;
      QTest::newRow("A Valid Port")<<(QStringList()<<"foo"<<"--qTestable-port=1124"<<"baz")<<1124<<2;
    }

    void shouldBeAbleToReadPort()
    {
      QFETCH(QStringList, arguments);
      QFETCH(int, port);
      QFETCH(int, finalSize);

      ConfigParser parser(arguments);
      QCOMPARE(parser.port, port);
      QCOMPARE(arguments.size(), finalSize);
    }
};

QTEST_MAIN(ConfigParserTest)
#include "ConfigParserTest.moc"
