#include <QApplication>
#include <QPushButton>

#include <QTestableApplication.h>

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  QTestableApplication testApp("org.qTestable.FT1", app.arguments());

  QPushButton button("foobar");
  button.show();

  return app.exec();
}
