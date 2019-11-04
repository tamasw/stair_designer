#include "gtest/gtest.h"

#include "geometry/Point.hpp"
#include "geometry/Line.hpp"

using namespace geometry;

TEST(LineTest, exception)
{
    Point p1(0, 0);
    Point p2(0, 0);
    EXPECT_THROW(Line::newInstance(p1, p2), std::runtime_error);
}