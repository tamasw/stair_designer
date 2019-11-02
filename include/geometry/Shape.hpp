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
    
}


