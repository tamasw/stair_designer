#pragma once

#include <optional>

#include "util/Optional.hpp"
#include "Shape.hpp"
#include "Point.hpp"

namespace geometry {

class Line : public Shape {
    public:
        static Line* newInstance(const Point& point1, const Point& point2);
        
        virtual double getXOffset() const = 0;
        virtual double getYOffset() const = 0;
        virtual double getAngle() const = 0;
        
        virtual util::Optional<Point> getPointAtX(const double x) const = 0;
        virtual util::Optional<Point> getPointAtY(const double y) const = 0;
        
    protected:
        Line(Shape::Type type);
        
};

}

