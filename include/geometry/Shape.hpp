#pragma once

#include <functional>

namespace geometry {

class Shape {
    public:
        enum Type {
            POINT,
            CUSTOM_LINE,
            HORIZONTAL_LINE
        };
        
        Type getType() const { return type; }
        
        virtual ~Shape() {}
    protected:
        Shape(Type type) : type(type) {}
        
    private:
        Type type;
};    
    
}

