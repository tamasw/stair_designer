#include <functional>

#include "geometry/shapes.hpp"

namespace geometry {
    
Point::Point(double x, double y)
: Shape(Shape::Type::POINT)
, x(x)
, y(y)
{}
        
bool Point::operator==(const Point& other) const
{
    return
            x == other.x &&
            y == other.y;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}


bool Point::operator !=(const Point& other) const
{
    return !(*this == other);
}

PointComparator Point::comparator() {
    return PointComparator();
}

const Point& Point::getMinX(const Point& p1, const Point& p2)
{
    return p1.getX() < p2.getY() ? p1 : p2;
}

PointComparator::PointComparator()
: getterFunction(std::bind(&Point::getX, std::placeholders::_1))
, comparatorFunction(std::less<double>())
{
}

PointComparator& PointComparator::onXAxis() {
    getterFunction = std::bind(&Point::getX, std::placeholders::_1);
    return *this;
}

PointComparator& PointComparator::onYAxis() {
    getterFunction = std::bind(&Point::getY, std::placeholders::_1);
    return *this;
}

PointComparator& PointComparator::min() {
    comparatorFunction = std::less<double>();
    return *this;
}

PointComparator& PointComparator::max() {
    comparatorFunction = std::greater<double>();
    return *this;
}

Point& PointComparator::operator()(Point& point1, Point& point2) {
    double value1 = getterFunction(point1);
    double value2 = getterFunction(point2);
    return comparatorFunction(value1, value2) ? point1 : point2;
}

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

}

