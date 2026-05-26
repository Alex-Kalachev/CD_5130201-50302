#pragma once

#include <iostream>

class Rect{

    private:
        // int m_left;
        // int m_right;
        // int m_top;
        // int m_bottom;

        int m_x;
        int m_y;
        int m_width;
        int m_height;

    public:

        Rect(){
            // m_left = 0;
            // m_right = 0;
            // m_top = 0;
            // m_bottom = 0;
            m_x = 0;
            m_y = 0;
            m_width = 0;
            m_height = 0;
            std::cout << "Вызван конструткор по умолчанию, адрес объекта " << this << "\n";
        }


        Rect(int left, int right, int top, int bottom){

            // m_left = std::min(left, right);
            // m_right = std::max(left, right);
            // m_top = std::max(top, bottom);
            // m_bottom = std::min(top, bottom);

            set_all(left, right, top, bottom);
            std::cout << "Вызван конструткор с параметрами, адрес объекта " << this << "\n";

        }

        Rect(const Rect &other);

        ~Rect(){
            std::cout << "Вызван деструтор.\n";
        }
//1.8
        int get_left() const;
        int get_right() const;
        int get_top() const;
        int get_bottom() const;

        void set_all(int left, int right, int top, int bottom);

//1.9
        void inflate(int amount);
        void inflate(int dw, int dh);
        void inflate(int d_left, int d_right, int d_top, int d_bottom);
        void move(int x, int y = 0);

//1.11

        int get_width() const;
        int get_height() const;
        int get_square() const;

        void set_width(int width);
        void set_height(int height);

};

//1.10
Rect bounding_rect(Rect r1, Rect r2);
void print_rect(const Rect &r);