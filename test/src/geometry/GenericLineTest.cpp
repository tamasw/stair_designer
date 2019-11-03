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
    
    template<class T, typename... Args>
    T getResult(std::unique_ptr<Line>& line, std::function<util::Optional<T>(Line*, Args...)> function, Args... args)
    {
        return function(line.get(), args...).get();
    }
    
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
    std::function<util::Optional<double>(Line*)> getXOffset(&Line::getXOffset);
    
    ASSERT_EQ(0, getResult(simpleLine, getXOffset));
    ASSERT_EQ(-2, getResult(offsetedLine, getXOffset));
    ASSERT_EQ(0, getResult(steepLine, getXOffset));
    ASSERT_EQ(-1.5, getResult(steepOffsetedLine, getXOffset));
    ASSERT_EQ(2.5, getResult(reverseLine, getXOffset));
}

TEST_F(GenericLineTest, yOffsets)
{
    std::function<util::Optional<double>(Line*)> getYOffset(&Line::getYOffset);
    
    ASSERT_EQ(0, getResult(simpleLine, getYOffset));
    ASSERT_EQ(2, getResult(offsetedLine, getYOffset));
    ASSERT_EQ(0, getResult(steepLine, getYOffset));
    ASSERT_EQ(3, getResult(steepOffsetedLine, getYOffset));
    ASSERT_EQ(5, getResult(reverseLine, getYOffset));
}

TEST_F(GenericLineTest, angles)
{
    std::function<util::Optional<double>(Line*)> getAngle(&Line::getAngle);
    
    ASSERT_EQ(1, getResult(simpleLine, getAngle));
    ASSERT_EQ(1, getResult(offsetedLine, getAngle));
    ASSERT_EQ(4, getResult(steepLine, getAngle));
    ASSERT_EQ(2, getResult(steepOffsetedLine, getAngle));
    ASSERT_EQ(-2, getResult(reverseLine, getAngle));
}

TEST_F(GenericLineTest, pointAtX)
{
    std::function<util::Optional<Point>(Line*, double)> getPointAtX(&Line::getPointAtX);
    
    ASSERT_EQ(Point(10, 10), getResult(simpleLine, getPointAtX, 10.0));
    ASSERT_EQ(Point(-3, -3), getResult(simpleLine, getPointAtX, -3.0));
    
    ASSERT_EQ(Point(10, 12), getResult(offsetedLine, getPointAtX, 10.0));
    ASSERT_EQ(Point(-3, -1), getResult(offsetedLine, getPointAtX, -3.0));
    
    ASSERT_EQ(Point(10, 40), getResult(steepLine, getPointAtX, 10.0));
    ASSERT_EQ(Point(-3, -12), getResult(steepLine, getPointAtX, -3.0));
 
    ASSERT_EQ(Point(10, 23), getResult(steepOffsetedLine, getPointAtX, 10.0));
    ASSERT_EQ(Point(-3, -3), getResult(steepOffsetedLine, getPointAtX, -3.0));
    
    ASSERT_EQ(Point(10, -15), getResult(reverseLine, getPointAtX, 10.0));
    ASSERT_EQ(Point(-3, 11), getResult(reverseLine, getPointAtX, -3.0));
}

TEST_F(GenericLineTest, pointAtY)
{
    std::function<util::Optional<Point>(Line*, double)> getPointAtY(&Line::getPointAtY);
    
    ASSERT_EQ(Point(10, 10), getResult(simpleLine, getPointAtY, 10.0));
    ASSERT_EQ(Point(-3, -3), getResult(simpleLine, getPointAtY, -3.0));
    
    ASSERT_EQ(Point(10, 12), getResult(offsetedLine, getPointAtY, 12.0));
    ASSERT_EQ(Point(-3, -1), getResult(offsetedLine, getPointAtY, -1.0));
    
    ASSERT_EQ(Point(10, 40), getResult(steepLine, getPointAtY, 40.0));
    ASSERT_EQ(Point(-3, -12), getResult(steepLine, getPointAtY, -12.0));
 
    ASSERT_EQ(Point(10, 23), getResult(steepOffsetedLine, getPointAtY, 23.0));
    ASSERT_EQ(Point(-3, -3), getResult(steepOffsetedLine, getPointAtY, -3.0));
    
    ASSERT_EQ(Point(10, -15), getResult(reverseLine, getPointAtY, -15.0));
    ASSERT_EQ(Point(-3, 11), getResult(reverseLine, getPointAtY, 11.0));
}
