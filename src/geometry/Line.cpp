#include "geometry/Line.hpp"
#include "geometry/CustomLine.hpp"
#include "geometry/HorizontalLine.hpp"

using namespace geometry;

Line* Line::newInstance(const Point& point1, const Point& point2)
{
    if(isHorizontal(point1, point2)) {
        return nullptr;
    }
    const Point& minX = Point::comparator().min().onXAxis()(point1, point2);
    const Point& maxX = Point::comparator().max().onXAxis()(point1, point2);
    double angle = (maxX.getY() - minX.getY()) / (maxX.getX() - minX.getX());
    double offset = maxX.getX() - maxX.getY() / angle;
    return new CustomLine(offset, angle);
}

bool Line::isHorizontal(const Point& point1, const Point& point2)
{
    return point1.getY() == point2.getY();
}

Line::Line(Shape::Type type)
: Shape(type)
{
}
