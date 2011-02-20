#include <QApplication>

#include <QTestableApplication.h>

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableApplication testApp(app.arguments());

  return app.exec();
}
