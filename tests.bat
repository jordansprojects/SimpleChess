@echo off
REM Run Google Tests via CMake without using Gradle
echo Building, Compiling and Running CMake Tests
mkdir build
cmake -S . -B build
cmake --build build
cd build
ctest
cd ..
