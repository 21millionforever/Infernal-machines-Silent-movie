/**
 * @file Motor.h
 * @author Zhendong Chen
 *
 * Class that represent a motor
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "RotationSource.h"

/**
 * Class that represent a motor
 */
class Motor : public Component {
private:
    /// The speed of the motor
    double mSpeed;

    /// The body of the motor
    std::shared_ptr<Polygon> mBody = std::make_shared<Polygon>();

    /// Rotation source for this component
    RotationSource mSource;

    /// The position of the body
    wxPoint mBodyPosition;


public:

    /// Constructor
    Motor(const std::wstring& imagesDir1,const std::wstring& imagesDir2, int wheelWid, int bodyWid);

    /// Copy constructor/disabled
    Motor(const Motor&) = delete;

    /// Assignment operator/disabled
    void operator=(const Motor&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetTime(double time);

    void SetRotation(double rotation) override;

    void SetSpeed(double speed);

    /**
     * Get Rotation source
     * @return Rotation source
     */
    RotationSource *GetSource() { return &mSource; }

    /**
     * Set the position for the body
     * @param pos The position for the body
     */
    void SetBodyPosition(wxPoint pos) {mBodyPosition = pos;}

};

#endif //CANADIANEXPERIENCE_MOTOR_H
