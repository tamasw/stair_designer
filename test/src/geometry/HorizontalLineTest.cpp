#include <memory>

#include "gtest/gtest.h"
#include "geometry/Line.hpp"
#include "geometry/HorizontalLine.hpp"
#include "LineTester.hpp"

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
    LineTester<double, double> tester(&Line::getYOffset);
    ASSERT_EQ(2, tester.getResult(horizontalLine));
}

TEST_F(HorizontalLineTest, angle)
{
    ASSERT_FALSE(horizontalLine->getAngle().available());
}

TEST_F(HorizontalLineTest, getPointAtX)
{
    LineTester<Point&, Shape, double> tester(&Line::getShapeAtX);
    ASSERT_EQ(Point(3, 2), tester.getResult(horizontalLine, 3));
}

TEST_F(HorizontalLineTest, getPointAtY)
{
    LineTester<HorizontalLine, Shape, double> tester(&Line::getShapeAtY);
    ASSERT_EQ(Shape::Type::HORIZONTAL_LINE, tester.getResult(horizontalLine, 2).getType());
    ASSERT_EQ(2.0, tester.getResult(horizontalLine, 2).getYOffset().get());
}

TEST_F(HorizontalLineTest, getPointAtY_invalid)
{
    LineTester<HorizontalLine, Shape, double> tester(&Line::getShapeAtY);
    ASSERT_FALSE(horizontalLine->getShapeAtY(100).available());
}