#pragma once

#include "Line.hpp"

namespace geometry {
    
class VerticalLine : public Line {
    public:
        util::Optional<double> getXOffset() const override;
        util::Optional<double> getYOffset() const override;
        util::Optional<double> getAngle() const override;
        
        util::Optional<Shape> getShapeAtX(const double x) const override;
        util::Optional<Shape> getShapeAtY(const double y) const override;
        
    protected:
        VerticalLine(double yOffset);
        
        double xOffset;
        
        friend class Line;    
};    
    
}