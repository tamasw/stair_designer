#include "geometry/HorizontalLine.hpp"
#include "geometry/Shape.hpp"

using namespace geometry;

HorizontalLine::HorizontalLine(double yOffset)
: yOffset(yOffset)
, Line(Shape::Type::HORIZONTAL_LINE)
{
}

util::Optional<double> HorizontalLine::getXOffset() const
{
    return util::Optional<double>::empty();
}
util::Optional<double> HorizontalLine::getYOffset() const
{
    return util::Optional<double>::of(yOffset);

}

util::Optional<double> HorizontalLine::getAngle() const
{
    return util::Optional<double>::empty();
}
        
util::Optional<Shape> HorizontalLine::getShapeAtX(const double x) const
{
    return util::Optional<Point>::of(Point(x, yOffset));
}

util::Optional<Shape> HorizontalLine::getShapeAtY(const double y) const
{
    if(y == yOffset) {
        return util::Optional<HorizontalLine>::of(HorizontalLine(yOffset));
    }
    return util::Optional<Shape>::empty();
}

