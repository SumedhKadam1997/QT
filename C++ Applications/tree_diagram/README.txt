Build system used is g++ build system from Visual Studio Code

Steps followed during building application:
1) Configure a new build task from Terminal.
2) Select the compiler.(This steps creates tasks.json)
3) Add "-std=c++17" in args section of tasks.json
4) Run the build task from Terminal by keeping the cpp file active in editor.
5) Finished

Manual build steps:
C:\MinGW\bin\g++.exe -g "Path to folder containing\tree.cpp" -o "Path to folder where we want\tree.exe" -std=c++17