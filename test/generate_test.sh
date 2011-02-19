#! /bin/sh

if [ "$1" == "" ]; then
  echo "Usage: $0 NewClassName"
  exit 1
fi

sed "s/blah/$1/g" test_template.cpp > "$1Test.cpp"
echo "do_test($1Test)" >> CMakeLists.txt
