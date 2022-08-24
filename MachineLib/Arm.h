/**
 * @file Arm.h
 * @author Zhendong Chen
 *
 * Class represents an arm
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "RotationSink.h"
#include "PositionSource.h"

/**
 * Class represents an arm
 */
class Arm : public Component {
private:
    /// The length of the arm
    double mLength;

    /// Arm's rotation sink(arm is a rotation sink)
    RotationSink mSink;

    /// Arm's position sink(Arm is a position source)
    PositionSource mPositionSource;

public:
    Arm(int length);

    /// Copy constructor/disabled
    Arm(const Arm&) = delete;

    /// Assignment operator/disabled
    void operator=(const Arm&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetRotation(double rotation) override;

    /**
     * Get the Rotation sink
     * @return Rotation sink
     */
    RotationSink *GetSink() {return &mSink;}

    /**
     * Get the Position source
     * @return Position source
     */
    PositionSource *GetPositionSource() {return &mPositionSource; }

};

#endif //CANADIANEXPERIENCE_ARM_H
