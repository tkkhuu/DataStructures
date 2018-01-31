//
//  matrix.cpp
//  DataStructures
//
//  Created by Tri Khuu on 1/30/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "matrix.hpp"

using namespace Matrix;

Matrix2D::Matrix2D(unsigned long _rows, unsigned long _cols) : rows(_rows), cols(_cols)
{
    vector<double> row (_cols, 0);
    for (int i = 0; i < _rows; i++)
    {
        data.push_back(row);
    }
}

Matrix2D::Matrix2D(vector<vector<double> > grid)
: rows(grid.size()), cols(grid[0].size()), data(grid)
{}

unsigned long Matrix2D::CountRows()
{
    return rows;
}

unsigned long Matrix2D::CountColumns()
{
    return cols;
}

vector<double>& Matrix2D::operator[](const unsigned long& index)
{
    if(index > rows - 1)
    {
        cout << "Error accessing Matrix2D data: Index out of range"<< endl;
        exit(0);
    }
    return data[index];
}

Matrix2D& Matrix2D::operator=(const Matrix2D& rhs)
{
    if(this != &rhs)
    {
        data = rhs.data;
        rows = rhs.rows;
        cols = rhs.cols;
    }
    return *this;
}

Matrix2D& Matrix2D::operator+=(const Matrix::Matrix2D &rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        cout << "Error Adding Matrix2D: Matrix dimensions don't match" << endl;
        exit(0);
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double temp_value = rhs.data[i][j];
            data[i][j] += temp_value;
        }
    }
    
    return *this;
}

Matrix2D& Matrix2D::operator-=(const Matrix::Matrix2D &rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        cout << "Error Adding Matrix2D: Matrix dimensions don't match" << endl;
        exit(0);
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double temp_value = rhs.data[i][j];
            data[i][j] -= temp_value;
        }
    }
    
    return *this;
}

Matrix2D& Matrix2D::operator*=(const double& scalar)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            data[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix2D& Matrix2D::operator*=(const Matrix2D& rhs)
{
    if(cols != rhs.rows)
    {
        cout << "Error Multiplying Matrix2D: Matrix dimensions don't match" << endl;
        exit(0);
    }
    
    vector<vector<double> > new_data (rows, vector<double>(rhs.cols, 0));
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rhs.cols; j++)
        {
            for(int k = 0; k < rhs.rows; k++)
            {
                new_data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    data = new_data;
    cols = rhs.cols;
    return *this;
}

Matrix2D Matrix2D::operator+(const Matrix2D& rhs)
{
    Matrix2D result = *this;
    result += rhs;
    return result;
}

Matrix2D Matrix2D::operator-(const Matrix2D& rhs)
{
    Matrix2D result = *this;
    result -= rhs;
    return result;
}

Matrix2D Matrix2D::operator*(const Matrix2D& rhs)
{
    Matrix2D result = *this;
    result *= rhs;
    return result;
}


Matrix2D Matrix2D::operator*(const double& scalar)
{
    Matrix2D result = *this;
    result *= scalar;
    return result;
}
