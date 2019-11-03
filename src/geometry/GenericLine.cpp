#include "geometry/GenericLine.hpp"

using namespace geometry;

GenericLine::GenericLine(double xOffset, double angle)
: Line(Shape::Type::GENERIC_LINE)
, xOffset(xOffset)
, angle(angle)
{
}

double GenericLine::getXOffset() const {
    return xOffset;
}

double GenericLine::getYOffset() const {
    return -1 * (angle * xOffset);
}

double GenericLine::getAngle() const {
    return angle;
}
        
util::Optional<Point> GenericLine::getPointAtX(const double x) const {
    return util::Optional<Point>::of(Point(x, x*angle + getYOffset()));
}

util::Optional<Point> GenericLine::getPointAtY(const double y) const {
    return util::Optional<Point>::of(Point(xOffset + y / angle, y));
}

