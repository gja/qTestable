#include "ConfigParser.h"

#include <QRegExp>

ConfigParser::ConfigParser(QStringList &arguments) : port(0)
{
  foreach(QString string, arguments)
  {
    QRegExp regex("--qTestable-port=(\\d+)");
    if(regex.indexIn(string) != -1)
    {
      arguments.removeAll(string);
      port = regex.cap(1).toInt();
    }
  }
}
