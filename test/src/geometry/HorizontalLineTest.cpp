#include <memory>

#include "gtest/gtest.h"
#include "geometry/Line.hpp"

using namespace geometry;

class HorizontalLineTest : public ::testing::Test {
protected:
    HorizontalLineTest()
    : Test()
    {}
    
    static std::unique_ptr<Line> horizontalLine;
};

std::unique_ptr<Line> HorizontalLineTest::horizontalLine(Line::newInstance(Point(0, 2), Point(1, 2)));

TEST_F(HorizontalLineTest, type) 
{
    ASSERT_EQ(Shape::Type::HORIZONTAL_LINE, horizontalLine->getType());
}

TEST_F(HorizontalLineTest, xOffset)
{
    ASSERT_FALSE(horizontalLine->getXOffset().available());
}

TEST_F(HorizontalLineTest, yOffset)
{
    ASSERT_EQ(2, horizontalLine->getYOffset().get());
}

TEST_F(HorizontalLineTest, angle)
{
    ASSERT_FALSE(horizontalLine->getAngle().available());
}

TEST_F(HorizontalLineTest, getPointAtX)
{
    ASSERT_EQ(Point(3, 2), horizontalLine->getPointAtX(3).get());
}

TEST_F(HorizontalLineTest, getPointAtY)
{
    ASSERT_FALSE(horizontalLine->getAngle().available());
}
