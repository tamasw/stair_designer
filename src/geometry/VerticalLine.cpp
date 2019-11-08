#include "geometry/VerticalLine.hpp"
#include "geometry/Shape.hpp"

using namespace geometry;

VerticalLine::VerticalLine(double xOffset)
: xOffset(xOffset)
, Line(Shape::Type::VERTICAL_LINE)
{
}

util::Optional<double> VerticalLine::getXOffset() const
{
    return util::Optional<double>::of(xOffset);
}

util::Optional<double> VerticalLine::getYOffset() const
{
    return util::Optional<double>::empty();
}

util::Optional<double> VerticalLine::getAngle() const
{
    return util::Optional<double>::empty();
}
        
util::Optional<Shape> VerticalLine::getShapeAtY(const double y) const
{
    return util::Optional<Point>::of(Point(xOffset, y));
}

util::Optional<Shape> VerticalLine::getShapeAtX(const double x) const
{
    if(x == xOffset) {
        return util::Optional<VerticalLine>::of(VerticalLine(xOffset));
    }
    return util::Optional<Shape>::empty();
}
