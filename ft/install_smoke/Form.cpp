#include "Form.h"

Form::Form(QWidget *parent)
{
  setupUi(this);
}

void Form::buttonClicked()
{
  label->setText("clicked");
}
