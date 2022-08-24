/**
 * @file Gear.h
 * @author Zhendong Chen
 *
 * Class that represent gear
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down

/// PI * 2 constant
const double PI2 = M_PI * 2;

/**
 * Class that represent gear
 */
class Gear : public Component {
private:
    /// The radius of the Gear
    double mRadius;

    /// The number of teeth for the Gear
    int mNumTeeth;

    /// Gear's rotation source(Gear is a rotation source)
    RotationSource mSource;

    /// Gear's rotation sink(Gear is a rotation sink)
    RotationSink mSink;


public:
    Gear(double radius, int numTeeth);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetRotation(double rotation) override;

    /**
     * Get the Rotation sink
     * @return Rotation sink
     */
    RotationSink *GetSink() {return &mSink;}

    /**
     * Get the rotation source
     * @return Rotation source
     */
    RotationSource *GetSource() {return &mSource; }

    void Drive(std::shared_ptr<Gear> gear, double phase);
};

#endif //CANADIANEXPERIENCE_GEAR_H
