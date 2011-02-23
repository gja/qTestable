#include <QObject>
#include <QPushButton>
#include <QLabel>

class LabelToButtonConnector : QObject
{
  Q_OBJECT

    QLabel *label;
  public:
    LabelToButtonConnector(const QPushButton *button, QLabel *label);
  public slots:
    void buttonClicked();
};
