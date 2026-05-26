#include <iostream>
#include "rect.hpp"

Rect::Rect(const Rect &other){
    // m_left = other.m_left;
    // m_right = other.m_right;
    // m_top = other.m_top;
    // m_bottom = other.m_bottom;
    m_x = other.m_x;
    m_y = other.m_y;
    m_width = other.m_width;
    m_height = other.m_height;

    std::cout << "Вызван конструткор копирования, адрес объекта " << this << "\n";
}

int Rect::get_left() const{
    // return m_left;
    return m_x;

}

int Rect::get_right() const{
    // return m_right;
    return m_x + m_width;

}

int Rect::get_top() const{
    // return m_top;
    return m_y + m_height;

}

int Rect::get_bottom() const{
    // return m_bottom;
    return m_y;

}

void Rect::set_all(int left, int right, int top, int bottom){

    // m_left = std::min(left, right);
    // m_right = std::max(left, right);
    // m_top = std::max(top, bottom);
    // m_bottom = std::min(top, bottom);

    int l = std::min(left, right);
    int r = std::max(left, right);
    int t = std::max(top, bottom);
    int b = std::min(top, bottom);
    
    m_x = l;
    m_y = b;
    m_width = r - l;
    m_height = t - b;
}

void Rect::inflate(int amount){
    inflate(amount, amount, amount, amount);
}

void Rect::inflate(int dw, int dh){
    inflate(dw, dw, dh, dh);
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom){
    // m_left -= d_left;
    // m_right += d_right;
    // m_top += d_top;
    // m_bottom -= d_bottom;

    int new_left   = m_x - d_left;
    int new_right  = (m_x + m_width) + d_right;
    int new_bottom = m_y - d_bottom;
    int new_top    = (m_y + m_height) + d_top;
    

    set_all(new_left, new_right, new_top, new_bottom);
}

void Rect::move(int x, int y){
    // m_left += x;
    // m_right += x;
    // m_top += y;
    // m_bottom += y;
    m_x += x;
    m_y += y;

}

Rect bounding_rect(Rect r1, Rect r2){
    int l = std::min(r1.get_left(),r2.get_left());
    int r = std::max(r1.get_right(), r2.get_right());
    int t = std::max(r1.get_top(), r2.get_top());
    int b = std::min(r1.get_bottom(), r2.get_bottom());
    return Rect(l,r,t,b); // вызван конструтор с параметрами и конструтор копирования (но тут компилятор оптимизирует через move-конструтор копирования)
}

void print_rect(const Rect &r){
        std::cout << "Left: " << r.get_left()
              << ", Right: " << r.get_right()
              << ", Bottom: "<< r.get_bottom() 
              << ", Top: " << r.get_top()<< std::endl;


}

int Rect::get_width() const{
    return std::abs(this->get_right() - this->get_left());
}

int Rect::get_height() const{
    return std::abs(this->get_top() - this->get_bottom());
}


int Rect::get_square() const{
    return (this->get_height())*(this->get_width());
}

void Rect::set_width(int width){

    // this->m_right = this->m_left + width;
    // set_all(m_left, m_right, m_top, m_bottom);

    m_width = std::max(0, width);
}

void Rect::set_height(int height){
    // m_top = m_bottom + height;
    // set_all(m_left, m_right, m_top, m_bottom);
    m_height = std::max(0, height);
}