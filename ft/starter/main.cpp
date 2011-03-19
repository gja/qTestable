#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "QTestableProxy.h"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableProxy proxy("org.qTestable.FT", "/", QDBusConnection::sessionBus(), 0);

  QObject::connect(&proxy, SIGNAL(Starting()), &app, SLOT(quit()));

  if(proxy.IsEnabled())
    return 0;

  return app.exec();
}
