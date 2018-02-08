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

bool Matrix2D::operator== (const Matrix2D& rhs)
{
    if (rows != rhs.rows) return false;
    if (cols != rhs.cols) return false;
    return (data == rhs.data);
}

Matrix2D Matrix2D::NonMaximalSuppression(int window_size)
{
    Matrix2D result (rows, cols);
    
    int row_window_idx = 0;
    int col_window_idx = 0;
    
    while (row_window_idx < rows)
    {
        int max_val = data[row_window_idx][col_window_idx];
        
        vector<pair<int, int>> list_of_idx_max_val;
        
        for (int i = row_window_idx; i < row_window_idx + window_size; i++)
        {
            if (i >= rows) break;
            for (int j = col_window_idx; j < col_window_idx + window_size; j++)
            {
                if (j >= cols) break;
                if (data[i][j] == max_val)
                {
                    pair<int, int> temp (i, j);
                    list_of_idx_max_val.push_back(temp);
                }
                else if (data[i][j] > max_val)
                {
                    max_val = data[i][j];
                    list_of_idx_max_val.clear();
                    pair<int, int> temp (i, j);
                    list_of_idx_max_val.push_back(temp);
                }
            }
        }
        
        for (auto& e : list_of_idx_max_val)
        {
            int max_val_row_index = e.first;
            int max_val_col_index = e.second;
            result[max_val_row_index][max_val_col_index] = max_val;
        }
        
        col_window_idx += 1;
        if(col_window_idx >= cols)
        {
            row_window_idx += 1;
            col_window_idx = 0;
        }
    }
    
    
    return result;
}
