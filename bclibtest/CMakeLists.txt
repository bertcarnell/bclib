include_directories(${BCLIB_SOURCE_DIR}/bclibtest)
include_directories(${BCLIB_SOURCE_DIR})
# link_directories(none)
#target_link_libraries(none)

add_executable(bclibtest main.cpp matrixTest.cpp orderTest.cpp simpleAssertTest.cpp RWarningExceptionTest.cpp VersionTest.cpp)
