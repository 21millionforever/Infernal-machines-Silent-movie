/**
 * @file RotationSink.h
 * @author Zhendong Chen
 *
 * Class that receives rotation from its rotation source
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

#include "Sink.h"
#include "Component.h"

/**
 * Class that receives rotation from its rotation source
 */
class RotationSink : public Sink {
private:
    /// The speed of gear
    double mSpeed = 1;

    /// The rotation phrase of gear
    double mPhase = 0;



public:
    /// Constructor
    RotationSink();

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSink &) = delete;

    void UpdateRotation(double rotation);


    /**
     * Set speed for gear
     * @param speed The speed of gear
     */
    void SetSpeed(double speed) {mSpeed = speed; }

    /**
     * Set rotaion phrase for gear
     * @param phase The rotation phrase of gear
     */
    void SetPhase(double phase) {mPhase = phase; }



};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
