#pragma once

#include "Shape.hpp"
#include "Point.hpp"

namespace geometry {

class Line : public Shape {
    public:
        Line(double offset, double angle);
        Line(const Point& p1, const Point& p2);
        
        double getOffset() const;
        double getAngle() const;
        
    protected:
        double offset;
        double angle;
};

}

