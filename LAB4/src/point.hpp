#pragma once


class Point{

    private:
        double m_x;
        double m_y;

    public:

    Point() :m_x(0),m_y(0) {}

    Point(double x, double y) :m_x(x), m_y(y) {}

    double get_x() const{
        return m_x;
    }

    double get_y() const{
        return m_y;
    }

    void set_x(double x){
        m_x = x;
    }

    void set_y(double y){
        m_y = y;
    }

    bool operator==(const Point& other) const{
        return (m_x == other.m_x && m_y == other.m_y);
    }

};