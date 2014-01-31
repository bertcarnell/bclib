#include "simpleAssertTest.h"

namespace bclibtest {
    
	void simpleAssertTest::Run()
	{
		printf("\tsimpleAssertTest...");
        testAssert();
		printf("passed\n");
	}
    
    void thrower()
    {
        throw std::runtime_error("thrower error");
    }
    
    void nothrower()
    {
        int five = 2 + 3;
    }
    
    void simpleAssertTest::testAssert()
    {
        ASSERT_NOTHROW(nothrower());
        ASSERT_THROW(thrower());
        bclib::Assert(true, "test1");
        ASSERT_ASSERTIONERROR(bclib::Assert(false, "test2"));
        bclib::Assert(1, 1, "test3");
        ASSERT_ASSERTIONERROR(bclib::Assert(0, 1, "test4"));
        bclib::Assert(1, 1, "test5");
        ASSERT_ASSERTIONERROR(bclib::Assert(0, 1, "test6"));
        bclib::AssertEqualsLRE(1.0, 1.0000000001, 6, "test7");
        bclib::AssertEqualsLRE(1.0, 1.0, 6, "test8");
        bclib::AssertEqualsLRE(1.01, 1.012, 1, "test9");
        bclib::AssertEqualsLRE(1.1, 1.01, 6, "test10");
    }
}

