bclib
=====

BertCarnell Template Library (bclib) for C++ utility headers

[![Build Status](https://travis-ci.org/bertcarnell/bclib.svg?branch=master)](https://travis-ci.org/bertcarnell/bclib)
[![codecov](https://codecov.io/gh/bertcarnell/bclib/branch/master/graph/badge.svg)](https://codecov.io/gh/bertcarnell/bclib)

## Developing using CMake on Windows and Linux

### Ubuntu Linux

#### Prereqs

Install `cmake` for cross-platform make, and `lcov` for coverage statistics.

```
sudo apt-get install cmake lcov
```

#### CMake

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Coverage
make
./bclibtest/bclibtest
lcov --directory bclibtest --capture --output-file bclibtest.info
lcov --remove bclibtest.info 'bclibtest/*' '/usr/*' --output-file bclibtest.clean.info
genhtml -o coverage bclibtest.clean.info
```

### Windows + Visual Studio

#### Prereqs

- Install [Visual Studio Community 2017](https://visualstudio.microsoft.com/vs/community/) with visual c++ support.
- Install [CMake](https://cmake.org/) for Windows

#### CMake

Open a Windows PowerShell window to run these commands

```
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64"
```

Open Visual Studio.  File -> Open -> Project/Solution -> bcblib.sln

- right click on ALL_BUILD -> build
- right click on bcblibtest -> Debug -> Start New Instance

Edit project properties as needed.  Transfer those flags to the CMakeLists.txt when satisfied.

### Windows + Rtools (for mingw)

#### Prereqs

Install [Rtools](https://cran.r-project.org/bin/windows/Rtools/)

#### CMake

Open a Windows command prompt (cmd)

```
mkdir build
cd build
"C:\Program Files\CMake\bin\cmake.exe" -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/Rtools/mingw_64/bin/g++.exe -DCMAKE_C_COMPILER=C:/Rtools/mingw_64/bin/gcc.exe -DCMAKE_MAKE_PROGRAM=C:/Rtools/mingw_64/bin/mingw32-make.exe -DCMAKE_BUILD_TYPE=Debug ..
C:\Rtools\mingw_64\bin\mingw32-make.exe
.\bclibtest\bclibtest.exe
```
