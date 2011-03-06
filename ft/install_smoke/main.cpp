#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include <qTestable/QTestable.h>

#include "Form.h"

using namespace QTestable;

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableService::startService("org.qTestable.FT", QApplication::arguments());
  QTestableService::registerStandardHandlers();

  Form form;
  form.show();

  QTestableService::registerObject("form", &form);
  QTestableService::registerObject("app", &app);

  return app.exec();
}
