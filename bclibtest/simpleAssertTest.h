/* 
 * File:   simpleAssertTest.h
 * Author: carnellr
 *
 * Created on January 31, 2014, 11:10 AM
 */

#ifndef SIMPLEASSERTTEST_H
#define	SIMPLEASSERTTEST_H

#include "..\TestClass.h"
#include "..\simpleAssert.h"

namespace bclibtest {
	class simpleAssertTest : public bclib::TestClass
	{
		void Run();
        void testAssert();
	};
}

#endif	/* SIMPLEASSERTTEST_H */

