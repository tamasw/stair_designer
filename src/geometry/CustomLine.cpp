#include "geometry/CustomLine.hpp"

using namespace geometry;

CustomLine::CustomLine(double xOffset, double angle)
: Line(Shape::Type::CUSTOM_LINE)
, xOffset(xOffset)
, angle(angle)
{
}

util::Optional<double> CustomLine::getXOffset() const {
    return util::Optional<double>::of(xOffset);
}

util::Optional<double> CustomLine::getYOffset() const {
    return util::Optional<double>::of(-1 * (angle * xOffset));
}

util::Optional<double> CustomLine::getAngle() const {
    return util::Optional<double>::of(angle);
}
        
util::Optional<Point> CustomLine::getPointAtX(const double x) const {
    return util::Optional<Point>::of(Point(x, x*angle + getYOffset().get()));
}

util::Optional<Point> CustomLine::getPointAtY(const double y) const {
    return util::Optional<Point>::of(Point(xOffset + y / angle, y));
}

