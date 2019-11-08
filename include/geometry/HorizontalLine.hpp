#pragma once

#include "Line.hpp"
#include "util/Optional.hpp"

namespace geometry {
    
class HorizontalLine : public Line {
    public:
        util::Optional<double> getXOffset() const override;
        util::Optional<double> getYOffset() const override;
        util::Optional<double> getAngle() const override;
        
        util::Optional<Shape> getShapeAtX(const double x) const override;
        util::Optional<Shape> getShapeAtY(const double y) const override;
        
    protected:
        HorizontalLine(double yOffset);
        
        double yOffset;
        
        friend class Line;    
};
    
}

