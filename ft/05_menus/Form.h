#ifndef FORM_H
#define FORM_H

#include<QMainWindow>

#include "ui_Form.h"

class Form : public QMainWindow, private Ui::Form
{
  Q_OBJECT

  public:
    Form(QWidget *parent = NULL);
};

#endif
