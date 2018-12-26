cmake_minimum_required(VERSION 2.8)
project(BCLIB)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14 /W3")

	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} /Zi /O0")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} /Ox")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS} /O2 /Zi")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 -Wall -pedantic -mtune=native -Werror -Wno-unknown-pragmas -Wno-long-long")

	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -O0")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS} -O2 -g")

	IF (CMAKE_BUILD_TYPE STREQUAL "Coverage")
	  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
	  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
	ENDIF()  
endif()


message(STATUS, "CXXFLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS, "Debug: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS, "Release: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS, "Linker: ${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(bclibtest)

