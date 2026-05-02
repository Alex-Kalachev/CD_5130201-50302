#pragma once
#include "point.hpp"
#include <cmath>

class Circle{

    private:
        Point m_centre;
        double m_radius;

    public:

        Circle() :m_centre(), m_radius(0){}

        Circle(double x, double y, double radius) :m_centre(x,y), m_radius(std::abs(radius)){}

        bool operator==(const Circle& other) const{
            return (m_centre == other.m_centre && m_radius == other.m_radius);
        }

        double get_radius() const{
            return m_radius;
        }

        Point get_center() const{
            return m_centre;
        }
};