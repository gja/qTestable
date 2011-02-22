#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include <QTestable.h>
#include "LabelToButtonConnector.h"
#include "Handler.h"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableService::startService("org.qTestable.FT2", app.arguments());

  QPushButton button("foobar");
  button.show();

  QLabel label("blah");
  label.show();

  QTestableService::registerInvalidRequestHandler(new Handler());
  QTestableService::registerObject("button", &button);
  QTestableService::registerObject("label", &label);
  QTestableService::registerObject("app", &app);

  LabelToButtonConnector connector(&button, &label);

  return app.exec();
}
