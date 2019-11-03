#pragma once

namespace geometry {
    
class HorizontalLine : public Line {
        util::Optional<double> getXOffset() const override;
        util::Optional<double> getYOffset() const override;
        util::Optional<double> getAngle() const override;
        
        util::Optional<Point> getPointAtX(const double x) const override;
        util::Optional<Point> getPointAtY(const double y) const override;
        
    protected:
        HorizontalLine(double yOffset);
        
        double yOffset;
        
        friend class Line;    
};
    
}

