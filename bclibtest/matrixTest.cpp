/**
 * @file matrixTest.cpp
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

#include "matrixTest.h"

namespace bclibtest {
    
	void matrixTest::Run()
	{
		printf("\tmatrixTest...");
        testGetRowColSize();
		testElementAccess();
        testConstructor();
        testGetRowCol();
        testIterators();
        testOperators();
        testToString();
		printf("passed\n");
	}
    
    void matrixTest::testGetRowColSize()
    {
        bclib::matrix<int> A = bclib::matrix<int>(3,9);
        bclib::Assert(3, A.rowsize());
        bclib::Assert(9, A.colsize());
    }

    void matrixTest::testElementAccess()
    {
        // assignment and access
        bclib::matrix<int> B = bclib::matrix<int>(2,3);
        B(0,0) = 3;
        bclib::Assert(3, B(0,0), "(i,j) assignment");
        B.at(0,0) = 4;
        bclib::Assert(4, B(0,0), ".at(i,j) assignment");
        B.at(0) = 5;
        bclib::Assert(5, B(0,0), ".at(loc) assignment");
        B.data()[0] = 6;
        bclib::Assert(6, B(0,0), ".data()[] assignment");

        // different kind of access
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        B = bclib::matrix<int>(2, 3, expected);
        for (int i = 0; i < B.rowsize(); i++)
        {
            for (int j = 0; j < B.colsize(); j++)
            {
                bclib::Assert(expected[i*B.colsize() + j], B(i,j), "(i,j) access");
            }
        }
        std::vector<int> actual = B.getDataVector();
        for (int i = 0; i < B.rowsize(); i++)
        {
            for (int j = 0; j < B.colsize(); j++)
            {
                bclib::Assert(expected[i*B.colsize() + j], actual[i*B.colsize() + j], "std::vector[loc] access");
            }
        }
        for (int i = 0; i < B.rowsize(); i++)
        {
            for (int j = 0; j < B.colsize(); j++)
            {
                bclib::Assert(expected[i*B.colsize() + j], B.at(i, j), ".at(i,j) access");
            }
        }
        for (int i = 0; i < B.rowsize(); i++)
        {
            for (int j = 0; j < B.colsize(); j++)
            {
                bclib::Assert(expected[i*B.colsize() + j], B.at(i*B.colsize() + j), ".at(loc) access");
            }
        }
        for (int i = 0; i < B.rowsize(); i++)
        {
            for (int j = 0; j < B.colsize(); j++)
            {
                bclib::Assert(expected[i*B.colsize() + j], B.data()[i*B.colsize() + j], ".data() access");
            }
        }
    }

    void matrixTest::testConstructor()
    {
        bclib::matrix<int> B = bclib::matrix<int>();
        bclib::Assert(0, B.rowsize());
        bclib::Assert(0, B.colsize());
        for (std::vector<int>::iterator i = B.getDataVector().begin(); i != B.getDataVector().end(); i++)
        {
            bclib::Assert(0, *i, "null constructor");
        }

        bclib::matrix<int> A = bclib::matrix<int>(3,9);
        bclib::Assert(3, A.rowsize());
        bclib::Assert(9, A.colsize());
        for (int i = 0; i < 3*9; i++)
        {
            bclib::Assert(0, A.at(i), "size constructor");
        }

        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        bclib::matrix<int> D = bclib::matrix<int>(2,3,expected);
        bclib::Assert(2, D.rowsize());
        bclib::Assert(3, D.colsize());
        bclib::Assert(expected[0], D.at(0), "std::vector constructor");
        bclib::Assert(expected[5], D.at(5), "std::vector constructor");

        int exp[8] = {1,2,3,4,5,6,7,8};
        bclib::matrix<int> E = bclib::matrix<int>(4, 2, exp);
        bclib::Assert(4, E.rowsize());
        bclib::Assert(2, E.colsize());
        bclib::Assert(exp[0], E.at(0), "int[] constructor");
        bclib::Assert(exp[3], E.at(3), "int[] constructor");

        // copy constructor
        bclib::matrix<int> F = bclib::matrix<int>(2, 4, exp);
        bclib::matrix<int> G = F;
        bclib::Assert(2, G.rowsize());
        bclib::Assert(4, G.colsize());
        bclib::Assert(exp[0], G.at(0), "copy constructor");
        bclib::Assert(exp[3], G.at(3), "copy constructor");

        bclib::Assert(F == G, "Equality comparison");
    }

    void matrixTest::testGetRowCol()
    {
        int exp[8] = {1,2,3,4,5,6,7,8};
        bclib::matrix<int> E = bclib::matrix<int>(2, 4, exp);
        std::vector<int> row = E.getrow(0);
        for (int i = 0; i < E.colsize(); i++)
        {
            bclib::Assert(exp[i], row[i], "getrow");
        }
        row = E.getrow(1);
        for (int i = 0; i < E.colsize(); i++)
        {
            bclib::Assert(exp[i+E.colsize()], row[i], "getrow");
        }
        row = E.getrow_at(0);
        for (int i = 0; i < E.colsize(); i++)
        {
            bclib::Assert(exp[i], row[i], "getrow_at");
        }
        row = E.getrow_at(1);
        for (int i = 0; i < E.colsize(); i++)
        {
            bclib::Assert(exp[i+E.colsize()], row[i], "getrow_at");
        }
        ASSERT_THROW(E.getrow_at(2));
    }
    
    void matrixTest::testIterators()
    {
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        bclib::matrix<int> A = bclib::matrix<int>(2, 3, expected);
        
        bclib::matrix<int>::iterator it = A.begin();
        bclib::Assert(*(expected.begin()), *it);
        bclib::Assert(expected[0], *it);
        
        it = A.end();
        bclib::Assert(expected[6] != *it);
        ASSERT_NOTHROW(++it); // iterating past the end does not throw
        
        it = A.begin();
        for (int i = 0; i < expected.size(); i++)
        {
            bclib::Assert(expected[i], *it);
            ++it;
        }
        
        bclib::matrix<int>::rowwise_iterator rit = A.rowwisebegin();
        bclib::Assert(*(expected.begin()), *rit);
        bclib::Assert(expected[0], *rit);
        
        rit = A.rowwiseend();
        bclib::Assert(expected[6] != *rit);
        ASSERT_NOTHROW(++rit); // iterating past the end does not throw
        
        rit = A.rowwisebegin();
        for (int i = 0; i < expected.size(); i++)
        {
            bclib::Assert(expected[i], *rit);
            ++rit;
        }
        
        bclib::matrix<int>::columnwise_iterator cit = A.columnwisebegin();
        bclib::Assert(*(expected.begin()), *cit);
        bclib::Assert(expected[0], *cit);
        
        cit = A.columnwiseend();
        bclib::Assert(expected[6] != *cit);
        ASSERT_NOTHROW(++cit); // iterating past the end does not throw
        
        cit = A.columnwisebegin();
        bclib::Assert(expected[0], *cit);
        ++cit;
        bclib::Assert(expected[3], *cit);
        ++cit;
        bclib::Assert(expected[1], *cit);
        ++cit;
        bclib::Assert(expected[4], *cit);
        ++cit;
        bclib::Assert(expected[2], *cit);
        ++cit;
        bclib::Assert(expected[5], *cit);
        
        int sum = std::accumulate(A.begin(), A.end(), 0);
        bclib::Assert(6*7/2, sum);
        int sum2 = std::accumulate(A.rowwisebegin(), A.rowwiseend(), 0);
        bclib::Assert(6*7/2, sum2);
        int sum3 = std::accumulate(A.columnwisebegin(), A.columnwiseend(), 0);
        bclib::Assert(6*7/2, sum3);
        
        std::vector<int> output = std::vector<int>(expected.size());
        std::transform(A.rowwisebegin(), A.rowwiseend(), A.columnwisebegin(), output.begin(), std::plus<int>());
        bclib::Assert(2, output[0]);
        bclib::Assert(12, output[5]);
        
        bclib::matrix<int>::iterator it2 = A.end();
        it = A.begin();
        it2 = it;
        bclib::Assert(it2 == A.begin());
        bclib::Assert(it2 != A.end());
        
        bclib::matrix<int>::rowwise_iterator rit2 = A.rowwiseend();
        rit = A.rowwisebegin();
        rit2 = rit;
        bclib::Assert(rit2 == A.rowwisebegin());
        bclib::Assert(rit2 != A.rowwiseend());

        bclib::matrix<int>::columnwise_iterator cit2 = A.columnwiseend();
        cit = A.columnwisebegin();
        cit2 = cit;
        bclib::Assert(cit2 == A.columnwisebegin());
        bclib::Assert(cit2 != A.columnwiseend());
        
        // check assignment for a std::vector non-const iterator
        it = A.begin();
        *it = 100;
        bclib::Assert(100, *(A.begin()));
        
        cit = A.columnwisebegin();
        ++cit;
        *cit = 300;
        bclib::Assert(300, *cit);
        bclib::Assert(300, A.getDataVector()[3]);

        rit = A.rowwisebegin();
        ++rit;
        ++rit;
        *rit = 400;
        bclib::Assert(400, *rit);
        bclib::Assert(400, A.getDataVector()[2]);        

        // verfified that this is a compiler error on assignment, but not on increment
#ifdef NOTDEFINED
        bclib::matrix<int>::const_iterator itc = A.begin();
        itc++;
        ++itc;
        *itc = 100;
        
        bclib::matrix<int>::const_columnwise_iterator citc = A.columnwisebegin();
        citc++;
        ++citc;
        *citc = 100;

        bclib::matrix<int>::const_rowwise_iterator ritc = A.rowwisebegin();
        ritc++;
        ++ritc;
        *ritc = 100;
#endif
        
        it = std::find(A.begin(), A.end(), 5);
        bclib::Assert(it != A.end());
        bclib::Assert(5, *it);
        cit = std::find(A.columnwisebegin(), A.columnwiseend(), 5);
        bclib::Assert(cit != A.columnwiseend());
        bclib::Assert(5, *cit);
        rit = std::find(A.rowwisebegin(), A.rowwiseend(), 5);
        bclib::Assert(rit != A.rowwiseend());
        
        std::vector<int> expected2 = {1, 2, 3, 4, 5, 6};
        bclib::matrix<int> B = bclib::matrix<int>(2, 3, expected2);
        int count = 0;
        for (bclib::matrix<int>::rowwise_iterator rowit = B.rowwisebegin(); 
                rowit != B.rowwiseend(); ++rowit, count++)
        {
            *rowit = count;
        }
        bclib::Assert(0, B(0,0));
        bclib::Assert(5, B(1,2));

        std::vector<double> Yvec = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
        bclib::matrix<double> Ymat = bclib::matrix<double>(2, 3, Yvec);
        bclib::matrix<double>::rowwise_iterator Yit = Ymat.rowwisebegin(0);
        for (int i = 0; i < 3; i++)
        {
            bclib::Assert(Yvec[i], *Yit, 1E-12);
            ++Yit;
        }
        bclib::Assert(Yit == Ymat.rowwiseend(0), "iterator problem");
        Yit = Ymat.rowwisebegin(1);
        for (int i = 3; i < 6; i++)
        {
            bclib::Assert(Yvec[i], *Yit, 1E-12);
            ++Yit;
        }
        bclib::Assert(Yit == Ymat.rowwiseend(1), "iterator problem");
        
        Ymat.transpose();
        Yit = Ymat.rowwisebegin(0);
        bclib::Assert(1.1, *Yit, 1E-12);
        ++Yit;
        bclib::Assert(4.4, *Yit, 1E-12);
        ++Yit;
        bclib::Assert(Yit == Ymat.rowwiseend(0));

        std::vector<double> Zvec = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
        bclib::matrix<double> Zmat = bclib::matrix<double>(3, 2, Zvec);
        bclib::matrix<double>::columnwise_iterator Zit = Zmat.columnwisebegin(0);
        for (int i = 0; i < 6; i+=2)
        {
            bclib::Assert(Zvec[i], *Zit, 1E-12);
            ++Zit;
        }
        bclib::Assert(Zit == Zmat.columnwiseend(0), "iterator problem");
        Zit = Zmat.columnwisebegin(1);
        for (int i = 1; i < 6; i+=2)
        {
            bclib::Assert(Zvec[i], *Zit, 1E-12);
            ++Zit;
        }
        bclib::Assert(Zit == Zmat.columnwiseend(1), "iterator problem");
    }
    
    void matrixTest::testOperators()
    {
        std::vector<int> A = {1,2,3,4,5,6,7,8};
        bclib::matrix<int> B = bclib::matrix<int>(4,2,A);
        std::vector<int> C = {9,10,11,12,13,14,15,16};
        bclib::matrix<int> D = bclib::matrix<int>(4,2,C);
        bclib::Assert(B != D);
        D = B;
        bclib::Assert(B == D);
    }
    
    void matrixTest::testToString()
    {
        std::vector<int> A = {1,2,3,4,5,6,7,8};
        bclib::matrix<int> B = bclib::matrix<int>(4,2,A);
        std::string expected = "1,2\n3,4\n5,6\n7,8\n";
        std::string result = B.toString();
        bclib::Assert(expected == result, "to string");
    }
} // end namespace
