#include "matrixTest.h"

namespace bclibtest {
    
	void matrixTest::Run()
	{
		printf("\tmatrixTest...");
        testGetRowColSize();
		testElementAccess();
        testConstructor();
        testGetRowCol();
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
} // end namespace
