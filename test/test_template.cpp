#include <QTest>

class blah : public QObject
{
  Q_OBJECT
  private slots:
    void shouldDoSomethingCool()
    {
      QVERIFY(true);
    }
};

QTEST_MAIN(blah)
#include "blah.moc"
