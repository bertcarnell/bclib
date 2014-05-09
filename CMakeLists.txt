cmake_minimum_required(VERSION 2.8)
project(BCLIB)

set(CMAKE_CXX_FLAGS "-g -std=c++0x -m64 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++0x -m64 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++0x -m64 -Wall")
set(CMAKe_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -std=c++0x -m64 -Wall")

add_subdirectory(bclibtest)
