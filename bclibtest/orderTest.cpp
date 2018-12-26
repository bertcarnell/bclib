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

#include "orderTest.h"

namespace bclibtest {
    
	void orderTest::Run()
	{
        printf("\torderTest...");
        testOrder();
        printf("passed\n");
	}
    
    void orderTest::testOrder()
    {
        std::vector<int> order = std::vector<int>(4);
        std::vector<double> toOrder = {1.0, 3.0, 2.0, 4.0};
        std::vector<int> expected = {1, 3, 2, 4};
        bclib::findorder(toOrder, order);
        bclib::Assert(static_cast<int>(expected.size()), static_cast<int>(order.size()), "wrong size");
        for (std::vector<int>::size_type i = 0; i < expected.size(); i++)
        {
            bclib::Assert(expected[i], order[i]);
        }
        bclib::findorder_zero(toOrder, order);
        bclib::Assert(static_cast<int>(expected.size()), static_cast<int>(order.size()), "wrong size");
        for (std::vector<int>::size_type i = 0; i < expected.size(); i++)
        {
            bclib::Assert(expected[i]-1, order[i]);
        }
        
        toOrder.push_back(-1.2);
        toOrder.push_back(-0.5);
        toOrder.push_back(0.5);
        toOrder.push_back(3.1);
        
        std::vector<int> expected2 = {5,6,7,1,3,2,8,4};
        bclib::findorder(toOrder, order);
        bclib::Assert(static_cast<int>(expected2.size()), static_cast<int>(order.size()), "wrong size");
        for (std::vector<int>::size_type i = 0; i < expected2.size(); i++)
        {
            bclib::Assert(expected2[i], order[i]);
        }
        bclib::findorder_zero(toOrder, order);
        bclib::Assert(static_cast<int>(expected2.size()), static_cast<int>(order.size()), "wrong size");
        for (std::vector<int>::size_type i = 0; i < expected2.size(); i++)
        {
            bclib::Assert(expected2[i]-1, order[i]);
        }
        
        std::pair<double, int> a = std::pair<double, int>(4.1, 1);
        std::pair<double, int> b = std::pair<double, int>(0.0, 2);
        
        bclib::Assert(bclib::findranksCompare<double>(a, b));
        bclib::Assert(!bclib::findranksCompare<double>(b, a));
        
        b = std::pair<double, int>(4.1, 1);
        bclib::Assert(!bclib::findranksCompare<double>(a, b));
    }
}


