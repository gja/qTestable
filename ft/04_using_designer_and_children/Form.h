#ifndef FORM_H
#define FORM_H

#include<QWidget>

#include "ui_Form.h"

class Form : public QWidget, private Ui::Form
{
  Q_OBJECT

  public:
    Form(QWidget *parent = NULL);

  public slots:
    void buttonClicked();
};

#endif
