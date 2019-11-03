#include "geometry/Line.hpp"
#include "geometry/GenericLine.hpp"

using namespace geometry;

Line* Line::newInstance(const Point& point1, const Point& point2) {
    const Point& minX = Point::comparator().min().onXAxis()(point1, point2);
    const Point& maxX = Point::comparator().max().onXAxis()(point1, point2);
    double angle = (maxX.getY() - minX.getY()) / (maxX.getX() - minX.getX());
    double offset = maxX.getX() - maxX.getY() / angle;
    return new GenericLine(offset, angle);
}

Line::Line(Shape::Type type)
: Shape(type)
{
}