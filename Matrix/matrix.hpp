//
//  matrix.hpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <vector>

using namespace std;

namespace Matrix
{
    class Matrix2D
    {
    private:
        unsigned long rows;
        unsigned long cols;
        
        vector<vector<double> > data;
        
    public:
        Matrix2D(unsigned long, unsigned long);
        Matrix2D(vector<vector<double> >);
        
        Matrix2D Transpose();
        unsigned long CountRows();
        unsigned long CountColumns();
        
        vector<double>& operator[] (const unsigned long&);
        Matrix2D operator+(const Matrix2D&);
        Matrix2D operator-(const Matrix2D&);
        Matrix2D operator*(const Matrix2D&);
        Matrix2D operator*(const double&);
        Matrix2D& operator=(const Matrix2D&);
        Matrix2D& operator+=(const Matrix2D&);
        Matrix2D& operator-=(const Matrix2D&);
        Matrix2D& operator*=(const Matrix2D&);
        Matrix2D& operator*=(const double&);
        
        
        static Matrix2D Zeros(unsigned long _rows, unsigned long _cols)
        {
            return Matrix2D(_rows, _cols);
        }
        
        static Matrix2D Identity(unsigned long _dim)
        {
            Matrix2D result(_dim, _dim);
            for (int i = 0; i < _dim; i++)
            {
                result[i][i] = 1;
            }
            return result;
        }
        
        static void PrintMatrix2D(Matrix2D& matrix)
        {
            unsigned long n_rows = matrix.CountRows();
            unsigned long n_cols = matrix.CountColumns();
            
            for (int i = 0; i < n_rows; i++)
            {
                for (int j = 0; j < n_cols; j++)
                {
                    if(j == 0) cout << "[";
                    cout << matrix[i][j];
                    if (j == n_cols - 1) cout << "]" << endl;
                    else cout << ", ";
                }
            }
        }
        
    };
};
#endif /* matrix_h */

