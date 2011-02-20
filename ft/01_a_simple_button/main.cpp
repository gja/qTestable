#include <QApplication>
#include <QPushButton>

#include <QTestableService.h>

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableService::startService("org.qTestable.FT1", app.arguments());

  QPushButton button("foobar");
  button.show();

  return app.exec();
}
