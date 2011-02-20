#include "QTestableApplication.h"
#include "ConfigParser.h"

struct QTestableApplicationPrivate
{
  bool isEnabled;
};

QTestableApplication::QTestableApplication(bool isEnabled)
{
  d = new QTestableApplicationPrivate();
  d->isEnabled = isEnabled;
}

QTestableApplication::QTestableApplication(const QStringList &arguments)
{
  ConfigParser parser(arguments);
  QTestableApplication(parser.isEnabled);
}

QTestableApplication::~QTestableApplication()
{
  delete d;
}
