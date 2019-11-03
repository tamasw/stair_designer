#include "gtest/gtest.h"

#include "geometry/Point.hpp"

using namespace geometry;

TEST(PointTest, point_type)
{
    Point p(1, 0);
    ASSERT_EQ(p.getType(), Shape::Type::POINT);
}

TEST(PointTest, point_getters)
{
    Point p(2, 4);
    ASSERT_EQ(2, p.getX());
    ASSERT_EQ(4, p.getY());
}

TEST(PointTest, point_setters)
{
    Point p(2, 4);
    p.setX(1);
    p.setY(5);
    ASSERT_EQ(p, Point(1, 5));
}

TEST(PointTest, point_equality)
{
    Point p1(0, 1);
    Point p2(0, 1);
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 != p2);
}

TEST(PointTest, point_unequality)
{
    Point p1(0, 3);
    Point p2(0, 1);
    ASSERT_FALSE(p1 == p2);
    ASSERT_TRUE(p1 != p2);
}

TEST(PointTest, point_comparator_min_x)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& min = Point::comparator().min().onXAxis()(p1, p2);
    ASSERT_EQ(min, p1);
}

TEST(PointTest, point_comparator_max_x)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& max = Point::comparator().max().onXAxis()(p1, p2);
    ASSERT_EQ(max, p2);
}

TEST(PointTest, point_comparator_min_y)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& min = Point::comparator().min().onYAxis()(p1, p2);
    ASSERT_EQ(min, p2);
}

TEST(PointTest, point_comparator_max_y)
{
    Point p1(2, 5);
    Point p2(5, 2);
    Point& max = Point::comparator().max().onYAxis()(p1, p2);
    ASSERT_EQ(max, p1);
}

