/**
 * @file matrixTest.h
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

#ifndef MATRIXTEST_H
#define	MATRIXTEST_H

#include <algorithm>
#include <numeric>
#include "TestClass.h"
#include "matrix.h"
#include "simpleAssert.h"

namespace bclibtest 
{
	class matrixTest : public bclib::TestClass
	{
		void Run();
        void testGetRowColSize();
        void testElementAccess();
        void testConstructor();
        void testGetRowCol();
        void testIterators();
        void testOperators();
        void testToString();
	};
}

#endif	/* MATRIXTEST_H */

