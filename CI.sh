#rm -rf zBuild
mkdir zBuild
cd zBuild
cmake .. -DUSE_TEST=ON && make && xvfb-run ctest
