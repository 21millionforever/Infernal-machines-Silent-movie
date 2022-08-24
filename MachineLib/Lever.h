/**
 * @file Lever.h
 * @author Zhendong Chen
 *
 * class that represent lever
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RodSink.h"
#include "RotationSource.h"
#include "PositionSource.h"

class Rod;
/**
 * class that represent lever
 */
class Lever : public Component {
private:
    /// This component is a rodSink
    RodSink mRodSink;

    /// The length of the lever
    double mLength;

    /// Rotation source for this component
    RotationSource mRotationSource;

    /// The length from the middle of the lever to the end
    double mDriveEnd;

    /// Lever is a position source
    PositionSource mPositionSource;


public:
    /// Constructor
    Lever(double length);

    /// Copy constructor/disabled
    Lever(const Lever&) = delete;

    /// Assignment operator/disabled
    void operator=(const Lever&) = delete;

    /**
     * Set Drive end
     * @param end The length from the middle of the lever to the end
     */
    void SetDriveEnd(double end) {mDriveEnd = end; }

    /**
     * Get Rod Sink
     * @return Rod Sink
     */
    RodSink *GetRodSink() {return &mRodSink;}

    void Negotiate(Rod *rod) override;

    /**
     * Get a return Pointer to RotationSource object
     * @return RotationSource
     */
    RotationSource *GetRotationSource() { return &mRotationSource; }



    /**
     * Get Position Source
     * @return position source
     */
    PositionSource *GetPositionSource() {return &mPositionSource; }

};

#endif //CANADIANEXPERIENCE_LEVER_H
