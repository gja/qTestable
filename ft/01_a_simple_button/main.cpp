#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include <QTestable.h>
#include "LabelToButtonConnector.h"

class Handler : public QTestableClassHandler
{
  virtual QString handleRequest(QObject *object, const QTestableAutomationRequest &request)
  {
    if(request.command == "click") {
      ((QPushButton *) object)->click();
      return "clicked";
    }

    if(request.command == "quit") {
      ((QApplication *) object)->quit();
      return "quit";
    }

    if(request.command == "getText") {
      return ((QLabel *) object)->text();
    }

    return "";
  }
};

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableService::startService("org.qTestable.FT1", app.arguments());

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
