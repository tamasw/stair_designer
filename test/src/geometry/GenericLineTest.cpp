#include <iostream>
#include <memory>
#include "gtest/gtest.h"

#include "geometry/GenericLine.hpp"

using namespace geometry;

class GenericLineTest : public ::testing::Test {
protected:
    GenericLineTest()
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

std::unique_ptr<Line> GenericLineTest::simpleLine(Line::newInstance(Point(0, 0), Point(2, 2)));
std::unique_ptr<Line> GenericLineTest::offsetedLine(Line::newInstance(Point(0, 2), Point(1, 3)));
std::unique_ptr<Line> GenericLineTest::steepLine(Line::newInstance(Point(1, 4), Point(2, 8)));
std::unique_ptr<Line> GenericLineTest::steepOffsetedLine(Line::newInstance(Point(0, 3), Point(1, 5)));
std::unique_ptr<Line> GenericLineTest::reverseLine(Line::newInstance(Point(0, 5), Point(1, 3)));

TEST_F(GenericLineTest, line_type)
{
    ASSERT_EQ(Shape::Type::GENERIC_LINE, simpleLine->getType());
    ASSERT_EQ(Shape::Type::GENERIC_LINE, offsetedLine->getType());
    ASSERT_EQ(Shape::Type::GENERIC_LINE, steepLine->getType());
    ASSERT_EQ(Shape::Type::GENERIC_LINE, steepOffsetedLine->getType());
    ASSERT_EQ(Shape::Type::GENERIC_LINE, reverseLine->getType());
}

TEST_F(GenericLineTest, xOffsets)
{
    ASSERT_EQ(0, simpleLine->getXOffset());
    ASSERT_EQ(-2, offsetedLine->getXOffset());
    ASSERT_EQ(0, steepLine->getXOffset());
    ASSERT_EQ(-1.5, steepOffsetedLine->getXOffset());
    ASSERT_EQ(2.5, reverseLine->getXOffset());
}

TEST_F(GenericLineTest, yOffsets)
{
    ASSERT_EQ(0, simpleLine->getYOffset());
    ASSERT_EQ(2, offsetedLine->getYOffset());
    ASSERT_EQ(0, steepLine->getYOffset());
    ASSERT_EQ(3, steepOffsetedLine->getYOffset());
    ASSERT_EQ(5, reverseLine->getYOffset());
}

TEST_F(GenericLineTest, angles)
{
    ASSERT_EQ(1, simpleLine->getAngle());
    ASSERT_EQ(1, offsetedLine->getAngle());
    ASSERT_EQ(4, steepLine->getAngle());
    ASSERT_EQ(2, steepOffsetedLine->getAngle());
    ASSERT_EQ(-2, reverseLine->getAngle());
}

TEST_F(GenericLineTest, pointAtX)
{
    ASSERT_EQ(Point(10, 10), simpleLine->getPointAtX(10).get());
    ASSERT_EQ(Point(-3, -3), simpleLine->getPointAtX(-3).get());
    
    ASSERT_EQ(Point(10, 12), offsetedLine->getPointAtX(10).get());
    ASSERT_EQ(Point(-3, -1), offsetedLine->getPointAtX(-3).get());
    
    ASSERT_EQ(Point(10, 40), steepLine->getPointAtX(10).get());
    ASSERT_EQ(Point(-3, -12), steepLine->getPointAtX(-3).get());
 
    ASSERT_EQ(Point(10, 23), steepOffsetedLine->getPointAtX(10).get());
    ASSERT_EQ(Point(-3, -3), steepOffsetedLine->getPointAtX(-3).get());
    
    ASSERT_EQ(Point(10, -15), reverseLine->getPointAtX(10).get());
    ASSERT_EQ(Point(-3, 11), reverseLine->getPointAtX(-3).get());
}

TEST_F(GenericLineTest, pointAtY)
{
    ASSERT_EQ(Point(10, 10), simpleLine->getPointAtY(10).get());
    ASSERT_EQ(Point(-3, -3), simpleLine->getPointAtY(-3).get());
    
    ASSERT_EQ(Point(10, 12), offsetedLine->getPointAtY(12).get());
    ASSERT_EQ(Point(-3, -1), offsetedLine->getPointAtY(-1).get());
    
    ASSERT_EQ(Point(10, 40), steepLine->getPointAtY(40).get());
    ASSERT_EQ(Point(-3, -12), steepLine->getPointAtY(-12).get());
 
    ASSERT_EQ(Point(10, 23), steepOffsetedLine->getPointAtY(23).get());
    ASSERT_EQ(Point(-3, -3), steepOffsetedLine->getPointAtY(-3).get());
    
    ASSERT_EQ(Point(10, -15), reverseLine->getPointAtY(-15).get());
    ASSERT_EQ(Point(-3, 11), reverseLine->getPointAtY(11).get());
}
