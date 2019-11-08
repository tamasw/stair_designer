#pragma once

#include <optional>

#include "util/Optional.hpp"
#include "Shape.hpp"
#include "Point.hpp"

namespace geometry {

class Line : public Shape {
    public:
        static Line* newInstance(const Point& point1, const Point& point2);
        
        virtual util::Optional<double> getXOffset() const = 0;
        virtual util::Optional<double> getYOffset() const = 0;
        virtual util::Optional<double> getAngle() const = 0;
        
        virtual util::Optional<Shape> getShapeAtX(const double x) const = 0;
        virtual util::Optional<Shape> getShapeAtY(const double y) const = 0;
        
    protected:
        Line(Shape::Type type);
    
    private:
        static void checkPoints(const Point& point1, const Point& point2);
        static bool isHorizontal(const Point& point1, const Point& point2);
        
        static Line* createHorizontalLine(const Point& point1, const Point& point2);
        static Line* createCustomLine(const Point& point1, const Point& point2);
};

}

