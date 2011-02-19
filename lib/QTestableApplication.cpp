#include "QTestableApplication.h"
#include "ConfigParser.h"

struct QTestableApplicationPrivate
{
  int port;
};

QTestableApplication::QTestableApplication(int argc, char **argv) : QApplication(argc, argv)
{
  d = new QTestableApplicationPrivate();

  QStringList args = arguments();
  QStringList &args2 = args;

  ConfigParser parser(args);
  d->port = parser.port;
}

QTestableApplication::~QTestableApplication()
{
  delete d;
}
