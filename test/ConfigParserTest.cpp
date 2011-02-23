#include <QTest>
#include "ConfigParser.h"

using namespace QTestable;

class ConfigParserTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldBeAbleToReadPort_data()
    {
      QTest::addColumn<QStringList>("arguments");
      QTest::addColumn<bool>("isEnabled");

      QTest::newRow("Empty List")<<QStringList()<<false;
      QTest::newRow("Irrelevant Arguments")<<(QStringList()<<"foo"<<"bar"<<"baz")<<false;
      QTest::newRow("enabled")<<(QStringList()<<"foo"<<"--enable-qTestable"<<"baz")<<true;
      QTest::newRow("disabled")<<(QStringList()<<"foo"<<"--disable-qTestable"<<"baz")<<false;
      QTest::newRow("both present")<<(QStringList()<<"foo"<<"--enable-qTestable"<<"--disable-qTestable"<<"baz")<<false;
    }

    void shouldBeAbleToReadPort()
    {
      QFETCH(QStringList, arguments);
      QFETCH(bool, isEnabled);

      ConfigParser parser(arguments);
      QCOMPARE(parser.isEnabled, isEnabled);
    }
};

QTEST_MAIN(ConfigParserTest)
#include "ConfigParserTest.moc"
