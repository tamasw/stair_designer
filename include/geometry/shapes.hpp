#pragma once

#include <functional>

namespace geometry {

class Shape {
    public:
        enum Type {
            POINT,
            LINE
        };
        
        Type getType() const { return type; }
        
    protected:
        Shape(Type type) : type(type) {}
        
    private:
        Type type;
};    
    
class PointComparator;

class Point : public Shape {
    public:
        Point(double x, double y);
        
        double getX() const;
        double getY() const;
        
        void setX(double x);
        void setY(double y);
        
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;
        
        static PointComparator comparator();
        static const Point& getMinX(const Point& p1, const Point& p2);
    private:
        double x, y;
};

class PointComparator {
    public:
        PointComparator();
        PointComparator& onXAxis();
        PointComparator& onYAxis();
        PointComparator& min();
        PointComparator& max();
        
        Point& operator()(Point& point1, Point& point2);
    private:
        std::function<double(const Point&)> getterFunction;
        std::function<bool(double, double)> comparatorFunction;
};

class Line : public Shape {
    public:
        Line(double offset, double angle);
        Line(const Point& p1, const Point& p2);
        
        double getOffset() const;
        double getAngle() const;
        
    protected:
        double offset;
        double angle;
};

}


