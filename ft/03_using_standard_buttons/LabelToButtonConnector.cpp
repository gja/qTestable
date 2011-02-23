#include <QObject>
#include <QPushButton>
#include <QLabel>

#include "LabelToButtonConnector.h"

LabelToButtonConnector::LabelToButtonConnector(const QPushButton *button, QLabel *label)
{
  this->label = label;
  connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void LabelToButtonConnector::buttonClicked()
{
  label->setText("clicked");
}
