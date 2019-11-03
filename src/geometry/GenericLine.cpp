#include "geometry/GenericLine.hpp"

using namespace geometry;

GenericLine::GenericLine(double xOffset, double angle)
: Line(Shape::Type::GENERIC_LINE)
, xOffset(xOffset)
, angle(angle)
{
}

util::Optional<double> GenericLine::getXOffset() const {
    return util::Optional<double>::of(xOffset);
}

util::Optional<double> GenericLine::getYOffset() const {
    return util::Optional<double>::of(-1 * (angle * xOffset));
}

util::Optional<double> GenericLine::getAngle() const {
    return util::Optional<double>::of(angle);
}
        
util::Optional<Point> GenericLine::getPointAtX(const double x) const {
    return util::Optional<Point>::of(Point(x, x*angle + getYOffset().get()));
}

util::Optional<Point> GenericLine::getPointAtY(const double y) const {
    return util::Optional<Point>::of(Point(xOffset + y / angle, y));
}

