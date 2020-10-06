# $1 should be Debug or Release or Clang

if [ "$(uname -s)" == "MSYS_NT-10.0-WOW" ]; then
  echo Windows Build
  cmake . -Bbuild -DCMAKE_BUILD_TYPE=$1 -G "Visual Studio 15 2017 Win64"
  cmake --build build --target ALL_BUILD --config $1
  ./build/bclibtest/$1/bclibtest.exe
elif [ "$1" = "Clang" ]; then
  # sudo apt-get install clang llvm
  echo Clang Build
  export CC=clang
  export CXX=clang++
  cmake . -Bbuild -DCMAKE_BUILD_TYPE=$1 -D_CMAKE_TOOLCHAIN_PREFIX='llvm-'  
  cmake --build build
  ./build/bclibtest/bclibtest
else
  echo Linux Build
  cmake . -Bbuild -DCMAKE_BUILD_TYPE=$1
  cmake --build build
  ./build/bclibtest/bclibtest
fi
