add_executable(bclibtest main.cpp matrixTest.cpp orderTest.cpp simpleAssertTest.cpp RWarningExceptionTest.cpp VersionTest.cpp)

target_include_directories(bclibtest PUBLIC ${CMAKE_SOURCE_DIR})
