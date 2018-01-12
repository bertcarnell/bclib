/**
 * @file simpleAssertTest.cpp
 * @author Robert Carnell
 * @copyright Copyright (c) 2013, Robert Carnell
 * 
 * @license <a href="http://www.gnu.org/licenses/gpl.html">GNU General Public License (GPL v3)</a>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    
    int nothrower()
    {
        return 2 + 3;
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

