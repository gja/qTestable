#! /bin/sh

if [ "$1" == "" ]; then
  echo "Usage: $0 NewClassName"
  exit 1
fi

cat > "$1.h" << EOF
#ifndef `echo $1 | tr '[:lower:]' '[:upper:]'`_H
#define `echo $1 | tr '[:lower:]' '[:upper:]'`_H

#include "common.h"

namespace QTestable
{
  class $1
  {
  };
}

#endif
EOF

cat > "$1.cpp" << EOF
#include "$1.h"

namespace QTestable
{
}
EOF

sed "s/\${BLANK}/$1.cpp \${BLANK}/" -i CMakeLists.txt
