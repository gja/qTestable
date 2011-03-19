#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "QTestableProxy.h"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableProxy proxy("org.qTestable.FT", "/", QDBusConnection::sessionBus(), 0);

  QObject::connect(&proxy, SIGNAL(Broadcast(QString)), &app, SLOT(quit()));

  return app.exec();
}
