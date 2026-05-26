#pragma once

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

    double get(int i, int j) const;

    void set(int i, int j, double value);

    int get_height()const;

    int get_width() const;

    void negate();

    void add_in_place(const Matrix &other);

    Matrix multiply(const Matrix &other) const;
};