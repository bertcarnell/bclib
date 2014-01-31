/* 
 * File:   matrixTest.h
 * Author: carnellr
 *
 * Created on January 30, 2014, 4:13 PM
 */

#ifndef MATRIXTEST_H
#define	MATRIXTEST_H

#include "..\TestClass.h"
#include "..\matrix.h"
#include "..\simpleAssert.h"

namespace bclibtest {
	class matrixTest : public bclib::TestClass
	{
		void Run();
        void testGetRowColSize();
        void testElementAccess();
        void testConstructor();
        void testGetRowCol();
	};
}

#endif	/* MATRIXTEST_H */

