#include <QApplication>

#include <QTestableApplication.h>

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableApplication testApp("org.qTestable.FT1", app.arguments());

  return app.exec();
}
