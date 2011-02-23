#ifndef QBUTTONHANDLER_H
#define QBUTTONHANDLER_H

#include "QTestableClassHandler.h"
#include "../common.h"

namespace QTestable
{
  class QButtonHandler : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      QButtonHandler(QString aHandlerName = "QButtonHandler");
  };
}

#endif
