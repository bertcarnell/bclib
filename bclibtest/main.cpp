#include <cstdlib>
#include <cstdio>
#include <vector>
#include "../TestClass.h"
#include "matrixTest.h"
#include "simpleAssertTest.h"

using namespace bclibtest;

int main(int argc, const char* argv[] )
{
    START_TESTS("Starting Simple Tests...\n");
	CREATE_TEST(matrixTest);
    CREATE_TEST(simpleAssertTest);
    EXECUTE_TESTS();
}
