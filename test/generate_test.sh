#! /bin/sh

if [ "$1" == "" ]; then
  echo "Usage: $0 NewClassName"
  exit 1
fi

sed 's/blah/$1/g' test_template.cpp > $1.cpp
echo "do_test($1)" >> CMakeLists.txt
