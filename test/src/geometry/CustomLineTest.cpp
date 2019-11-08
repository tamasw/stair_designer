#include <iostream>
#include <memory>
#include "gtest/gtest.h"

#include "LineTester.hpp"
#include "geometry/CustomLine.hpp"

using namespace geometry;

class CustomLineTest : public ::testing::Test {
protected:
    CustomLineTest()
    : Test()
    {}
    
    static void SetUpTestSuite() {}
    
    static void TearDownTestSuite() {}
    
    static std::unique_ptr<Line> simpleLine;
    static std::unique_ptr<Line> offsetedLine;
    static std::unique_ptr<Line> steepLine;
    static std::unique_ptr<Line> steepOffsetedLine;
    static std::unique_ptr<Line> reverseLine;

};

std::unique_ptr<Line> CustomLineTest::simpleLine(Line::newInstance(Point(0, 0), Point(2, 2)));
std::unique_ptr<Line> CustomLineTest::offsetedLine(Line::newInstance(Point(0, 2), Point(1, 3)));
std::unique_ptr<Line> CustomLineTest::steepLine(Line::newInstance(Point(1, 4), Point(2, 8)));
std::unique_ptr<Line> CustomLineTest::steepOffsetedLine(Line::newInstance(Point(0, 3), Point(1, 5)));
std::unique_ptr<Line> CustomLineTest::reverseLine(Line::newInstance(Point(0, 5), Point(1, 3)));

TEST_F(CustomLineTest, line_type)
{
    ASSERT_EQ(Shape::Type::CUSTOM_LINE, simpleLine->getType());
    ASSERT_EQ(Shape::Type::CUSTOM_LINE, offsetedLine->getType());
    ASSERT_EQ(Shape::Type::CUSTOM_LINE, steepLine->getType());
    ASSERT_EQ(Shape::Type::CUSTOM_LINE, steepOffsetedLine->getType());
    ASSERT_EQ(Shape::Type::CUSTOM_LINE, reverseLine->getType());
}

TEST_F(CustomLineTest, xOffsets)
{
    LineTester<double, double> tester(&Line::getXOffset);
    
    ASSERT_EQ(0, tester.getResult(simpleLine));
    ASSERT_EQ(0, tester.getResult(simpleLine));
    ASSERT_EQ(-2, tester.getResult(offsetedLine));
    ASSERT_EQ(0, tester.getResult(steepLine));
    ASSERT_EQ(-1.5, tester.getResult(steepOffsetedLine));
    ASSERT_EQ(2.5, tester.getResult(reverseLine));
}

TEST_F(CustomLineTest, yOffsets)
{
    LineTester<double, double> tester(&Line::getYOffset);
    
    ASSERT_EQ(0, tester.getResult(simpleLine));
    ASSERT_EQ(2, tester.getResult(offsetedLine));
    ASSERT_EQ(0, tester.getResult(steepLine));
    ASSERT_EQ(3, tester.getResult(steepOffsetedLine));
    ASSERT_EQ(5, tester.getResult(reverseLine));
}

TEST_F(CustomLineTest, angles)
{
    LineTester<double, double> tester(&Line::getAngle);
    
    ASSERT_EQ(1, tester.getResult(simpleLine));
    ASSERT_EQ(1, tester.getResult(offsetedLine));
    ASSERT_EQ(4, tester.getResult(steepLine));
    ASSERT_EQ(2, tester.getResult(steepOffsetedLine));
    ASSERT_EQ(-2, tester.getResult(reverseLine));
}

TEST_F(CustomLineTest, pointAtX)
{
    LineTester<Point, Shape, double> tester(&Line::getShapeAtX);
    
    ASSERT_EQ(Point(10, 10), tester.getResult(simpleLine, 10.0));
    ASSERT_EQ(Point(-3, -3), tester.getResult(simpleLine, -3.0));
    
    ASSERT_EQ(Point(10, 12), tester.getResult(offsetedLine, 10.0));
    ASSERT_EQ(Point(-3, -1), tester.getResult(offsetedLine, -3.0));
    
    ASSERT_EQ(Point(10, 40), tester.getResult(steepLine, 10.0));
    ASSERT_EQ(Point(-3, -12), tester.getResult(steepLine, -3.0));
 
    ASSERT_EQ(Point(10, 23), tester.getResult(steepOffsetedLine, 10.0));
    ASSERT_EQ(Point(-3, -3), tester.getResult(steepOffsetedLine, -3.0));
    
    ASSERT_EQ(Point(10, -15), tester.getResult(reverseLine, 10.0));
    ASSERT_EQ(Point(-3, 11), tester.getResult(reverseLine, -3.0));
}

TEST_F(CustomLineTest, pointAtY)
{
    LineTester<Point, Shape, double> tester(&Line::getShapeAtY);
    
    ASSERT_EQ(Point(10, 10), tester.getResult(simpleLine, 10.0));
    ASSERT_EQ(Point(-3, -3), tester.getResult(simpleLine, -3.0));
    
    ASSERT_EQ(Point(10, 12), tester.getResult(offsetedLine, 12.0));
    ASSERT_EQ(Point(-3, -1), tester.getResult(offsetedLine, -1.0));
    
    ASSERT_EQ(Point(10, 40), tester.getResult(steepLine, 40.0));
    ASSERT_EQ(Point(-3, -12), tester.getResult(steepLine, -12.0));
 
    ASSERT_EQ(Point(10, 23), tester.getResult(steepOffsetedLine, 23.0));
    ASSERT_EQ(Point(-3, -3), tester.getResult(steepOffsetedLine, -3.0));
    
    ASSERT_EQ(Point(10, -15), tester.getResult(reverseLine, -15.0));
    ASSERT_EQ(Point(-3, 11), tester.getResult(reverseLine, 11.0));
}
