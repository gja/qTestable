#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include <QTestableService.h>
#include "LabelToButtonConnector.h"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableService::startService("org.qTestable.FT1", app.arguments());

  QPushButton button("foobar");
  button.show();

  QLabel label("blah");
  label.show();

  LabelToButtonConnector connector(&button, &label);

  return app.exec();
}
