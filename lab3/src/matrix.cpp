#include <stdexcept>
#include "matrix.hpp"

double Matrix::get(int i, int j) const{
    if (i < 0 || i >= m_rows || j < 0 || j >= m_cols) {
       throw std::out_of_range("Index out of bounds");
    }

    return m_data[i][j];
}

void Matrix::set(int i, int j, double value){
    if (i < 0 || i >= m_rows || j < 0 || j >= m_cols) {
        throw std::out_of_range("Index out of bounds");
    }
    m_data[i][j] = value;
}

int Matrix::get_height()const{
    return m_rows;
}

int Matrix::get_width() const{
    return m_cols;
}

void Matrix::negate(){
    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_cols; j++){
            m_data[i][j] = (-1) * m_data[i][j];
        }
    }
}

void Matrix::add_in_place(const Matrix &other){
    if (m_rows != other.m_rows || m_cols != other.m_cols){
        throw std::invalid_argument("Size incompatibility");
    }
    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_cols; j++){
            m_data[i][j] += other.m_data[i][j];
        }
    }
}

Matrix Matrix::multiply(const Matrix &other) const{
    if (m_cols != other.m_rows){
        throw std::invalid_argument("Size incompatibility");
    }

    Matrix mult_matrix(m_rows,other.m_cols);

    for(int i = 0; i < m_rows; i++){
        for (int j = 0; j < other.m_cols; j++){
            for (int k = 0; k < m_cols; k++){
                mult_matrix.m_data[i][j] += (m_data[i][k])*(other.m_data[k][j]);
            }

        }
    }

    return mult_matrix;

}

Matrix operator* (const double x, const Matrix& other){

    Matrix res = other;

    for (int i = 0; i < res.m_rows; i++){
        for (int j = 0; j < res.m_cols; j++){
            res.m_data[i][j] *= x;
        }
    }
    
    return res;
    
}

Matrix operator- (const Matrix& other){

    Matrix res = other;
    res.negate();
    return res;

}
