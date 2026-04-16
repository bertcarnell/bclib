/**
 * @file RWarningExceptionTest.h
 * @author Robert Carnell
 * @copyright Copyright (c) 2020, Robert Carnell
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

#ifndef RWARNINGEXCEPTIONTEST_H
#define	RWARNINGEXCEPTIONTEST_H

#include "TestClass.h"
#include "simpleAssert.h"
#include "RWarningException.h"
#include <cstring> // for std::stcmp

namespace bclibtest
{
    class RWarningExceptionTest : public bclib::TestClass
    {
        void Run();
        void testConstruct();
        void testString();
    };
}

#endif	/* RWARNINGEXCEPTIONTEST_H */

