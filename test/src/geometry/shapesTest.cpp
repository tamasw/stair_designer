#include "geometry/shapes.hpp"

#include "gtest/gtest.h"
#include <iostream>

using namespace geometry;

TEST(point_type, geometry)
{
    Point p(1, 0);
    ASSERT_EQ(p.getType(), Shape::Type::POINT);
}

TEST(point_getters, geometry)
{
    Point p(2, 4);
    ASSERT_EQ(2, p.getX());
    ASSERT_EQ(4, p.getY());
}

TEST(point_setters, geometry)
{
    Point p(2, 4);
    p.setX(1);
    p.setY(5);
    ASSERT_EQ(p, Point(1, 5));
}

TEST(point_equality, geometry)
{
    Point p1(0, 1);
    Point p2(0, 1);
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 != p2);
}

TEST(point_unequality, geometry)
{
    Point p1(0, 3);
    Point p2(0, 1);
    ASSERT_FALSE(p1 == p2);
    ASSERT_TRUE(p1 != p2);
}

TEST(point_comparator_min_x, geometry)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& min = Point::comparator().min().onXAxis()(p1, p2);
    ASSERT_EQ(min, p1);
}

TEST(point_comparator_max_x, geometry)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& max = Point::comparator().max().onXAxis()(p1, p2);
    ASSERT_EQ(max, p2);
}

TEST(point_comparator_min_y, geometry)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& min = Point::comparator().min().onYAxis()(p1, p2);
    ASSERT_EQ(min, p2);
}

TEST(point_comparator_max_y, geometry)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& max = Point::comparator().max().onYAxis()(p1, p2);
    ASSERT_EQ(max, p1);
}

TEST(line_type, geometry)
{
    Line line(0, 1);
    ASSERT_EQ(Shape::Type::LINE, line.getType());
}

TEST(line_parameters, geometry)
{
    Line line(0, 1);
    ASSERT_EQ(0, line.getOffset());
    ASSERT_EQ(1, line.getAngle());
}

