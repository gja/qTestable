#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "common.h"

class ConfigParser
{
  public:
    ConfigParser(QStringList &arguments);

    int port;
};

#endif
