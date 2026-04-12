bclib
=====

bertcarnell Template Library (bclib) for C++ utility headers

|<sub>Code Coverage</sub>|<sub>Github Actions</sub>|
|:---:|:---:|
|[![codecov](https://codecov.io/gh/bertcarnell/bclib/branch/master/graph/badge.svg)](https://codecov.io/gh/bertcarnell/bclib)|![CMake](https://github.com/bertcarnell/bclib/workflows/CMake/badge.svg)|

## Used in packages...

- [oa](https://github.com/bertcarnell/oa)
- [lhslib](https://github.com/bertcarnell/lhslib)
- [lhs](https://github.com/bertcarnell/lhs)

## Developing using CMake on Windows and Linux

### Ubuntu Linux

#### Prereqs

Install `cmake` for cross-platform make, and `lcov` for coverage statistics.

```
sudo apt-get install cmake lcov
```

#### CMake

```
cmake . -Bbuild -DCMAKE_BUILD_TYPE=Debug -DBUILD_TYPE=Coverage
cmake --build build
./build/bclibtest/bclibtest
cd build
lcov --directory bclibtest --capture --output-file bclibtest.info
lcov --remove bclibtest.info 'bclibtest/*' '/usr/*' --output-file bclibtest.clean.info
genhtml -o coverage bclibtest.clean.info
```

### Windows + Visual Studio

#### Prereqs

- Install [Visual Studio Code and the Visual Studio C++ Expansion](https://code.visualstudio.com/docs/cpp/config-msvc)
- Install [CMake](https://cmake.org/) for Windows

#### CMake

Open a Developer Command Prompt

```
cmake . -DCMAKE_BUILD_TYPE=Release -Bbuild -G "NMake Makefiles"
cmake --build build --config Release
cd build
nmake
bclibtest/bclibtest.exe
```
