#ifndef PARSERESTREQUEST_H
#define PARSERESTREQUEST_H

#include "common.h"

class ParseRestRequest
{

  public:
    ParseRestRequest(const QString &requestURL);
    bool isValid;
    QString targetClass;
    QString targetObject;
    QString command;
    QString arguments;
};

#endif
