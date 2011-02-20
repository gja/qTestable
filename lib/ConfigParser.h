#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "common.h"

class ConfigParser
{
  public:
    ConfigParser(const QStringList &arguments);

    bool isEnabled;
};

#endif
