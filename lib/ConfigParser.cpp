#include "ConfigParser.h"

#include <QRegExp>

ConfigParser::ConfigParser(const QStringList &arguments) : isEnabled(false)
{
  foreach(QString string, arguments)
  {
    if (string == "--enable-qTestable") isEnabled = true;
    if (string == "--disable-qTestable") isEnabled = false;
  }
}
