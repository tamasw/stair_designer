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

TEST_F(GenericLineTest, angles)
{
    ASSERT_EQ(1, simpleLine->getAngle());
    ASSERT_EQ(1, offsetedLine->getAngle());
    ASSERT_EQ(4, steepLine->getAngle());
    ASSERT_EQ(2, steepOffsetedLine->getAngle());
    ASSERT_EQ(-2, reverseLine->getAngle());
}
