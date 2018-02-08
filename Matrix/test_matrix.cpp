//
//  test_matrix.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "test_matrix.hpp"

void TestMatrix2D()
{
    
    TestMatrix2DCountRows();
    TestMatrix2DCountColumns();
    TestMatrix2DIndexOperator();
    TestMatrix2DEqualOperator();
    TestMatrix2DPlusEqualOperator();
    TestMatrix2DMinusEqualOperator();
    TestMatrix2DMultiplyEqualScalarOperator();
    TestMatrix2DMultiplyEqualMatrixOperator();
    TestMatrix2DNonMaxSuppression();
}

void TestMatrix2DCountRows()
{
    try
    {
        Matrix2D matrix0 (6, 5);
        assert(matrix0.CountRows() == 6);
        cout << "Matrix2D Test Count Rows: Passed" << endl;
    }
    catch (...)
    {
        cout << "Matrix2D Test Count Rows: Failed" << endl;
    }
}

void TestMatrix2DCountColumns()
{
    try {
        Matrix2D matrix0 (6, 5);
        assert(matrix0.CountColumns() == 5);
        cout << "Matrix2D Test Count Columns: Passed" << endl;
    } catch (...) {
        cout << "Matrix2D Test Count Columns: Failed" << endl;
    }
    
}

void TestMatrix2DIndexOperator()
{
    try {
        
        Matrix2D matrix0 (6, 5);
        
        int value = 0;
        
        for (int i = 0; i < matrix0.CountRows(); i++)
        {
            for (int j = 0; j < matrix0.CountColumns(); j++)
            {
                matrix0[i][j] = value;
                value++;
            }
        }
        
        value = 0;
        for (int i = 0; i < matrix0.CountRows(); i++)
        {
            for (int j = 0; j < matrix0.CountColumns(); j++)
            {
                assert(matrix0[i][j] == value);
                value++;
            }
        }
        
        cout << "Matrix2D Test '[]' Operator: Passed" << endl;
    }
    catch(...)
    {
        cout << "Matrix2D Test '[]' Operator: Failed" << endl;
    }
}

void TestMatrix2DEqualOperator()
{
    // ========= Test Assigning to new variable =========
    try
    {
        Matrix2D matrix0 (3, 4);
        
        int value = 0;
        for(int i = 0; i < matrix0.CountRows(); i++)
        {
            for (int j = 0; j < matrix0.CountColumns(); j++)
            {
                matrix0[i][j] = value;
                value++;
            }
        }
        
        Matrix2D matrix1 = matrix0;
        assert(matrix1.CountColumns() == 4);
        assert(matrix1.CountRows() == 3);
        
        value = 0;
        for(int i = 0; i < matrix1.CountRows(); i++)
        {
            for (int j = 0; j < matrix1.CountColumns(); j++)
            {
                assert(matrix1[i][j] == value);
                value++;
            }
        }
        
        matrix0 = Matrix2D::Zeros(4, 2);
        
        value = 0;
        for(int i = 0; i < matrix1.CountRows(); i++)
        {
            for (int j = 0; j < matrix1.CountColumns(); j++)
            {
                assert(matrix1[i][j] == value);
                value++;
            }
        }
        
        for(int i = 0; i < matrix0.CountRows(); i++)
        {
            for (int j = 0; j < matrix0.CountColumns(); j++)
            {
                assert(matrix0[i][j] == 0);
            }
        }
    }
    catch(...)
    {
        cout << "Matrix2D Test '=' Operator: Failed" << endl;
    }
    
    
}

void TestMatrix2DPlusEqualOperator()
{
    try
    {
        vector<vector<double> > m0 = {
            {0, 2, 4},
            {6, 8, 10},
            {12, 14, 16},
            {18, 20, 22}
        };
        
        vector<vector<double> > m1 = {
            {1, 3, 5},
            {7, 9, 11},
            {13, 15, 17},
            {19, 21, 23}
        };
        
        vector<vector<double> > m2 = {
            {1, 5, 9},
            {13, 17, 21},
            {25, 29, 33},
            {37, 41, 45}
        };
        Matrix2D matrix0 (m0);
        Matrix2D matrix1 (m1);
        matrix0 += matrix1;
        for (int i = 0; i < matrix0.CountRows(); i++)
        {
            for (int j = 0; j < matrix0.CountColumns(); j++)
            {
                assert(matrix0[i][j] == m2[i][j]);
            }
        }
        
        cout << "Matrix2D Test '+=' Operator: Passed" << endl;
    }
    catch(...)
    {
        cout << "Matrix2D Test '+=' Operator: Failed" << endl;
    }
}

void TestMatrix2DMinusEqualOperator()
{
    try
    {
        vector<vector<double> > m0 = {
            {0, 2, 4},
            {6, 8, 10},
            {12, 14, 16},
            {18, 20, 22}
        };
        
        vector<vector<double> > m1 = {
            {1, 3, 5},
            {7, 9, 11},
            {13, 15, 17},
            {19, 21, 23}
        };
        
        vector<vector<double> > m2 (4, vector<double> (3, -1));
        
        Matrix2D matrix0 (m0);
        Matrix2D matrix1 (m1);
        matrix0 -= matrix1;
        for (int i = 0; i < matrix0.CountRows(); i++)
        {
            for (int j = 0; j < matrix0.CountColumns(); j++)
            {
                assert(matrix0[i][j] == m2[i][j]);
            }
        }
        
        cout << "Matrix2D Test '-=' Operator: Passed" << endl;
    }
    catch(...)
    {
        cout << "Matrix2D Test '-=' Operator: Failed" << endl;
    }
}

void TestMatrix2DMultiplyEqualMatrixOperator()
{
    try
    {
        vector<vector<double> > m0 = {
            {0, 2, 4},
            {6, 8, 10},
            {12, 14, 16},
            {18, 20, 22}
        };
        
        vector<vector<double> > m1 = {
            {1, 3, 5, 7},
            {9, 11, 13, 15},
            {17, 19, 21, 23}
        };
        
        vector<vector<double> > m2 = {
            {86, 98, 110, 122},
            {248, 296, 344, 392},
            {410, 494, 578, 662},
            {572, 692, 812, 932}
        };
        
        Matrix2D matrix0 (m0);
        Matrix2D matrix1 (m1);
        matrix0 *= m1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                assert(matrix0[i][j] == m2[i][j]);
            }
        }
        
        cout << "Matrix2D Test '*= matrix' Operator: Passed" << endl;
    }
    catch(...)
    {
        cout << "Matrix2D Test '*= matrix' Operator: Failed" << endl;
    }
}

void TestMatrix2DMultiplyEqualScalarOperator()
{
    try
    {
        vector<vector<double> > m0 = {
            {0, 2, 4},
            {6, 8, 10},
            {12, 14, 16},
            {18, 20, 22}
        };
        Matrix2D matrix0(m0);
        matrix0 *= 2;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                assert(matrix0[i][j] == (2 * m0[i][j]));
            }
        }
        
        cout << "Matrix2D Test '*= scalar' Operator: Passed" << endl;
    }
    catch(...)
    {
        cout << "Matrix2D Test '*= scalar' Operator: Failed" << endl;
    }
}

void TestMatrix2DNonMaxSuppression()
{
    try
    {
        Matrix2D m_matrix({
            {6, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12},
            {13,14, 15, 16}
        });
        
        Matrix2D non_max_result_wind_3 ({
            {0,     0,     0,     0},
            {0,     0,     0,     0},
            {0,     0,     11,     12},
            {0,     0,     15,     16}
        });
        Matrix2D non_max_result_wind_2 ({
            {6,     0,     0,     0},
            {0,     6,     7,     8},
            {0,     10,     11,     12},
            {0,     14,     15,     16}
        });
        Matrix2D test_result_wind3 = m_matrix.NonMaximalSuppression(3);
        Matrix2D test_result_wind2 = m_matrix.NonMaximalSuppression(2);
        
        assert(test_result_wind2 == non_max_result_wind_2);
        assert(test_result_wind3 == non_max_result_wind_3);
        
        cout << "Matrix2D Test Non Max Suppression Operator: Passed" << endl;
    }
    catch(...)
    {
        cout << "Matrix2D Test Non Max Suppression Operator: Failed" << endl;
    }
}


