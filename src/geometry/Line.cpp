#include "geometry/Line.hpp"

using namespace geometry;

Line::Line(double offset, double angle)
: Shape(Shape::Type::LINE)
, offset(offset)
, angle(angle)
{
}

Line::Line(const Point& p1, const Point& p2)
: Shape(Shape::Type::LINE)
{
    
}

double Line::getOffset() const
{
    return offset;
}

double Line::getAngle() const
{
    return angle;
}


