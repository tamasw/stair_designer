#include <exception>

#include "geometry/Line.hpp"
#include "geometry/CustomLine.hpp"
#include "geometry/HorizontalLine.hpp"

using namespace geometry;

Line* Line::newInstance(const Point& point1, const Point& point2)
{
    checkPoints(point1, point2);
    
    if(isHorizontal(point1, point2)) {
        return createHorizontalLine(point1, point2);
    }
    return createCustomLine(point1, point2);
}

void Line::checkPoints(const Point& point1, const Point& point2)
{
    if(point1 == point2)
    {
        throw std::runtime_error("Cannot create line from two equal points");
    }
}

Line* Line::createHorizontalLine(const Point& point1, const Point& point2)
{
    return new HorizontalLine(point1.getY());
}

Line* Line::createCustomLine(const Point& point1, const Point& point2) 
{
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
