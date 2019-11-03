#pragma once

#include "Shape.hpp"
#include "Line.hpp"

namespace geometry {
    
class GenericLine : public Line {
    
        double getXOffset() const override;
        double getYOffset() const override;
        double getAngle() const override;
        
        util::Optional<Point> getPointAtX(const double x) const override;
        util::Optional<Point> getPointAtY(const double y) const override;
        
    protected:
        GenericLine(double xOffset, double angle);
        
        double xOffset;
        double angle;
        
        friend class Line;
   }; 
    
}


