#pragma once

#include <iostream>
#include <functional>

#include "Shape.hpp"

namespace geometry {
    
class PointComparator;

class Point : public Shape {
    public:
        Point(double x, double y);
        
        double getX() const;
        double getY() const;
        
        void setX(double x);
        void setY(double y);
        
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;
        
        static PointComparator comparator();
        static const Point& getMinX(const Point& p1, const Point& p2);
    private:
        double x, y;
};

class PointComparator {
    public:
        
        PointComparator();
        PointComparator& onXAxis();
        PointComparator& onYAxis();
        PointComparator& min();
        PointComparator& max();
        
        template <class P>
        auto operator()(P& point1, P& point2) -> decltype(point1)
        {
            double value1 = getterFunction(point1);
            double value2 = getterFunction(point2);
            return comparatorFunction(value1, value2) ? point1 : point2;
        }
    private:
        std::function<double(const Point&)> getterFunction;
        std::function<bool(double, double)> comparatorFunction;
};

}

std::ostream& operator<<(std::ostream& out, const geometry::Point& point);


