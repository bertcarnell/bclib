/**
 * @file RWarningExceptionTest.cpp
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

#include "RWarningExceptionTest.h"

namespace bclibtest {

    void RWarningExceptionTest::Run()
    {
        printf("\tRWarningExceptionTest...");
        testConstruct();
        printf("passed\n");
    }

    void RWarningExceptionTest::testConstruct()
    {
        int test = 1;
        try {
            throw bclib::RWarningException("Test One");
        }
        catch (bclib::RWarningException rwe)
        {
            bclib::Assert(1, test);
            bclib::Assert(strcmp(rwe.what(), "Test One") == 0);
        }
        catch (std::runtime_error e)
        {
            bclib::Assert(false, "Should not catch another type derived from a std::exception");
        }
        catch (std::exception e)
        {
            bclib::Assert(false, "Should not catch a base std::exception after catching a RWarningException");
        }

        try {
            throw bclib::RWarningException("Two Two Two");
        }
        catch (std::logic_error e)
        {
            bclib::Assert(false, "Should not catch another type derived from a std::exception");
        }
        catch (...)
        {
            bclib::Assert(1, test);
            bclib::Assert(true);
        }

        try {
            throw bclib::RWarningException("Three");
        }
        catch (std::exception e)
        {
            bclib::Assert(1, test);
            bclib::Assert(true);
        }
        catch (...)
        {
            bclib::Assert(false, "Should not catch in the default when the base class is present");
        }
    }

    void RWarningExceptionTest::testString()
    {
        const char * ccs = "Message 1";
        std::string ss = "Message 2";

        try {
            throw bclib::RWarningException(ccs);
        }
        catch (bclib::RWarningException rwe)
        {
            bclib::Assert(strcmp(ccs, rwe.what()));
        }

        try {
            throw bclib::RWarningException(ss);
        }
        catch (bclib::RWarningException rwe)
        {
            bclib::Assert(ss == rwe.what());
        }
    }

} // end namespace
