#include <iostream>
#include "gtest/gtest.h"

#include "geometry/Line.hpp"

using namespace geometry;

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

