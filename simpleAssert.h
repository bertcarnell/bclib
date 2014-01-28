/* 
 * File:   simpleAssert.h
 * Author: carnellr
 *
 * Created on December 6, 2013, 6:14 PM
 */

#ifndef SIMPLEASSERT_H
#define	SIMPLEASSERT_H

#include <math.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>

namespace bclib
{
    inline
    void Assert(bool test, std::string msg)
	{
		if (!test)
			throw std::runtime_error(msg.append("\n\n").c_str());
	}
    
    inline
    void Assert(bool test)
    {
        Assert(test, "Error in test - unknown location");
    }
    
    inline
    void Assert(int expected, int actual, std::string msg)
    {
        Assert(expected == actual, msg);
    }
    
    inline
    void Assert(int expected, int actual)
    {
        Assert(expected == actual, "Error in integer comparison, unknown location");
    }
    
    /**
     * Assert that expected and actual are equal to within a certain log relative error.
     * Log relative error measures the number of significant digits of agreement.
     * @param message message if the test fails
     * @param expected
     * @param actual
     * @param lre log relative error desired
     */
    inline
    void AssertEqualsLRE(double expected, double actual, int lre, std::string message)
    {
        double testlre;
        if (expected == actual)
        {
            return;
        }
        if (expected == 0.0)
        {
            testlre = -1.0 * log10(abs(actual));
        }
        else
        {
            testlre = -1.0 * log10(abs(actual-expected)) + log10(abs(expected));
        }
        
        if (isinf(testlre)) // C99 only
        {
            return;
        }
        if (testlre >= (double) std::numeric_limits<int>::max())
        {
            return;
        }
        if ((int) floor(testlre) < lre)
        {
            std::ostringstream mess;
            mess << "LRE is " << testlre << ", expected LRE is " << lre << " for " << actual << " vs " << expected;
            if (!message.empty())
            {
                mess << "\n" << message.c_str();
            }
            throw std::runtime_error(mess.str().c_str());
        }
    }

    inline
    void AssertEqualsLRE(double expected, double actual, int lre)
    {
        AssertEqualsLRE(expected, actual, lre, "");
    }

} //  end namespace


#endif	/* SIMPLEASSERT_H */

