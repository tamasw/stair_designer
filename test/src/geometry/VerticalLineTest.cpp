#include <memory>

#include "gtest/gtest.h"
#include "geometry/Line.hpp"
#include "geometry/VerticalLine.hpp"
#include "LineTester.hpp"

using namespace geometry;

class VerticalLineTest : public ::testing::Test {
protected:
    VerticalLineTest()
    : Test()
    {}
    
    static std::unique_ptr<Line> verticalLine;
};

std::unique_ptr<Line> VerticalLineTest::verticalLine(Line::newInstance(Point(1, 2), Point(1, 3)));

TEST_F(VerticalLineTest, type) 
{
    ASSERT_EQ(Shape::Type::VERTICAL_LINE, verticalLine->getType());
}

TEST_F(VerticalLineTest, yOffset)
{
    ASSERT_FALSE(verticalLine->getYOffset().available());
}

TEST_F(VerticalLineTest, xOffset)
{
    LineTester<double, double> tester(&Line::getXOffset);
    ASSERT_EQ(1, tester.getResult(verticalLine));
}

TEST_F(VerticalLineTest, angle)
{
    ASSERT_FALSE(verticalLine->getAngle().available());
}

TEST_F(VerticalLineTest, getPointAtY)
{
    LineTester<Point&, Shape, double> tester(&Line::getShapeAtY);
    ASSERT_EQ(Point(1, 4), tester.getResult(verticalLine, 4));
}

TEST_F(VerticalLineTest, getPointAtX)
{
    LineTester<VerticalLine, Shape, double> tester(&Line::getShapeAtX);
    ASSERT_EQ(Shape::Type::VERTICAL_LINE, tester.getResult(verticalLine, 1).getType());
    ASSERT_EQ(1.0, tester.getResult(verticalLine, 1).getXOffset().get());
}

TEST_F(VerticalLineTest, getPointAtX_invalid)
{
    ASSERT_FALSE(verticalLine->getShapeAtX(100).available());
}
