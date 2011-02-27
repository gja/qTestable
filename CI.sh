rm -rf zBuild
mkdir zBuild
cd zBuild
cmake .. -DUSE_TEST=ON || exit -1
make || exit -1
ctest || exit -1
