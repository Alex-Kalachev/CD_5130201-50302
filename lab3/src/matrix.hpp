#pragma once

#include <iostream>

class Matrix{

    private:
    double **m_data;
    int m_rows; //  строка - m
    int m_cols; // столбец - n

    public:

    Matrix(int n){

        m_rows = n;
        m_cols = n;
        m_data = new double *[m_rows];
        for (int i = 0; i < n; i++)
        {
            m_data[i] = new double[m_cols]();

            m_data[i][i] = 1.0;
        }
    }

    Matrix(int m, int n, double fill_value = 0){

        m_rows = m;
        m_cols = n;
        m_data = new double *[m_rows];
        for (int i = 0; i < m_rows; i++)
        {
            m_data[i] = new double[m_cols];

            for (int j = 0; j < m_cols; j++){
                m_data[i][j] = fill_value;
            }

        }

    }

    Matrix(const Matrix &other){
        m_rows = other.m_rows;
        m_cols = other.m_cols;

        m_data = new double *[other.m_rows];
        for (int i = 0; i < other.m_rows; i++){
            m_data[i] = new double[other.m_cols];

            for (int j = 0; j < other.m_cols; j++){
                m_data[i][j] = other.m_data[i][j];
            }

        }
    }

    ~Matrix(){
        for (int i = 0; i < m_rows; i++){
            delete[] m_data[i];
        }
        delete[] m_data;
    }

    // 1.1 оператор присваивания
    Matrix& operator=(const Matrix& other){

        if (this == &other) {
            return *this;
        }
        std::cout << "new\n";
        for (int i = 0; i < m_rows; i++){
            delete[] m_data[i];
        }
        delete[] m_data;

        m_rows = other.m_rows;
        m_cols = other.m_cols;

        m_data = new double *[other.m_rows];

        for (int i = 0; i < other.m_rows; i++){
            m_data[i] = new double[other.m_cols];

            for (int j = 0; j < other.m_cols; j++){
                m_data[i][j] = other.m_data[i][j];
            }
        }

        return *this;
    }
    // 1.1 оператор сложения матриц
    Matrix& operator+=(const Matrix& other){

        if (m_rows != other.m_rows || m_cols != other.m_cols){
            throw std::invalid_argument("Index out of range\n");
        }

        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                m_data[i][j] += other.m_data[i][j];
            }
        }
    
        return *this;
    }
    // 1.1 оператор вычитания матриц
    Matrix& operator-=(const Matrix& other){
        
        if (m_rows != other.m_rows || m_cols != other.m_cols){
            throw std::invalid_argument("Index out of range\n");
        }

        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                m_data[i][j] -= other.m_data[i][j];
            }
        }
    
        return *this;
    }
    // 1.1 оператор умнежения матрицы на число
    Matrix& operator*=(const double x){


        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                m_data[i][j] *= x;
            }
        }
    
        return *this;
    }
    // 1.1 оператор деления матрицы на число
    Matrix& operator/=(const double x){

        if (x == 0){
            throw std::invalid_argument("Division by zero");
        }

        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                m_data[i][j] /= x;
            }
        }
    
        return *this;
    }

    Matrix operator+(const Matrix& other) const {

        Matrix res = *this;
        res += other;
        return res;

    }

    Matrix operator-(const Matrix& other) const {

        Matrix res = *this;
        res -= other;
        return res;
        
    }

    Matrix operator*(const double x) const {

        Matrix res = *this;
        res *= x;
        return res;
        
    }

    Matrix operator/(const double x) const {

        Matrix res = *this;
        res /= x;
        return res;
        
    }

    Matrix operator*(const Matrix& other) const{
        return multiply(other);
    }

    Matrix(Matrix&& other){

        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_data = other.m_data;

        other.m_rows = 0;
        other.m_cols = 0;
        other.m_data = nullptr;
        
    }

    Matrix& operator=(Matrix&& other){

        if (this == &other){
            return *this;
        }

        for (int i = 0; i < m_rows; i++) {
            delete[] m_data[i];
        }

        delete[] m_data;

        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_data = other.m_data;

        other.m_rows = 0;
        other.m_cols = 0;
        other.m_data = nullptr;

        return *this;
    }

    friend Matrix operator* (double x, const Matrix& other);

    friend Matrix operator- (const Matrix& other);

    double get(int i, int j) const;

    void set(int i, int j, double value);

    int get_height()const;

    int get_width() const;

    void negate();

    void add_in_place(const Matrix &other);

    Matrix multiply(const Matrix &other) const;
    
};

