#! /bin/sh

if [ "$1" == "" ]; then
  echo "Usage: $0 NewClassName"
  exit 1
fi

CLASSNAME="$1Handler"

cat > "handlers/$CLASSNAME.h" << EOF
#ifndef `echo $CLASSNAME | tr '[:lower:]' '[:upper:]'`_H
#define `echo $CLASSNAME | tr '[:lower:]' '[:upper:]'`_H

#include "../common.h"
#include "QTestableClassHandler.h"

namespace QTestable
{
  class $CLASSNAME : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      $CLASSNAME(QString aHandlerName = "$CLASSNAME");
  };
}

#endif
EOF

cat > "handlers/$CLASSNAME.cpp" << EOF
#include "$CLASSNAME.h"

namespace QTestable
{
  $CLASSNAME::$CLASSNAME(QString aHandlerName) : QNamedClassHandler(aHandlerName)
  {}
}
EOF

sed "s,\${BLANK},handlers/$CLASSNAME.cpp \${BLANK}," -i CMakeLists.txt
sed "s,\${HBLANK},handlers/$CLASSNAME.h \${HBLANK}," -i CMakeLists.txt
