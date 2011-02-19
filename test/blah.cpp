#include <iostream>
#include <QTest>

class blah : public QObject
{
  Q_OBJECT
  private slots:
    void testSomething()
    {
      QVERIFY(true);
    }
};

QTEST_MAIN(blah)
#include "blah.moc"
