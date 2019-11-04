#pragma once

#include "Shape.hpp"
#include "Line.hpp"

namespace geometry {
    
class CustomLine : public Line {
    
        util::Optional<double> getXOffset() const override;
        util::Optional<double> getYOffset() const override;
        util::Optional<double> getAngle() const override;
        
        util::Optional<Point> getPointAtX(const double x) const override;
        util::Optional<Point> getPointAtY(const double y) const override;
        
    protected:
        CustomLine(double xOffset, double angle);
        
        double xOffset;
        double angle;
        
        friend class Line;
   }; 
    
}


