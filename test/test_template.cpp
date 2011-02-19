#include <QTest>
#include "blah.h"

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
