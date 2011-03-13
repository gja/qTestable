#! /bin/sh

if [ "$1" == "" ]; then
  echo "Usage: $0 NewClassName"
  exit 1
fi

CLASSNAME="handler_for_$1"

cat > "handlers/$CLASSNAME.h" << EOF
#ifndef `echo $CLASSNAME | tr '[:lower:]' '[:upper:]'`_H
#define `echo $CLASSNAME | tr '[:lower:]' '[:upper:]'`_H

#include "../common.h"
#include "QTestableClassHandler.h"
#include "qjson/serializer.h"

namespace QTestable
{
  class $CLASSNAME : public QNamedClassHandler
  {
    Q_OBJECT

    public:
      $CLASSNAME(QString aHandlerName = "$1") : QNamedClassHandler(aHandlerName) {}

    private slots:
      // QString foo(QObject *object, const QTestableAutomationRequest &request)
  };
}

#endif
EOF

#sed "s,\${BLANK},handlers/$CLASSNAME.h \${BLANK}," -i CMakeLists.txt
sed "s,\${HBLANK},handlers/$CLASSNAME.h \${HBLANK}," -i CMakeLists.txt
sed "s,//NEXTINCLUDEHERE,#include \"handlers/$CLASSNAME.h\"\n//NEXTINCLUDEHERE ," -i StandardHandlers.cpp
sed "s,//NEXTHANDLERHERE,static IQTestableClassHandler *$1Handler();\n      //NEXTHANDLERHERE," -i ../include/StandardHandlers.h
sed "s,//NEXTHANDLERHERE,dispatcher.registerClass(\"$1\"\, StandardHandlers::$1Handler());\n        //NEXTHANDLERHERE," -i QTestableService.cpp

cat >> StandardHandlers.cpp << EOF

IQTestableClassHandler *QTestable::StandardHandlers::$1Handler()
{
  return new $CLASSNAME("$1");
}
EOF
