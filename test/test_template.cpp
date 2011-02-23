#include <QTest>
#include "blah.h"

using namespace QTestable;

class blahTest : public QObject
{
  Q_OBJECT
  private slots:
    void shouldDoSomethingCool()
    {
      QVERIFY(true);
    }
};

QTEST_MAIN(blahTest)
#include "blahTest.moc"
