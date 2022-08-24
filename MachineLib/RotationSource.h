/**
 * @file RotationSource.h
 * @author Zhendong Chen
 *
 * Rotation Source in the components
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include "RotationSink.h"

/**
 * Rotation Source in the components
 */
class RotationSource {
private:
//    /// Rotation sink
//    RotationSink *mRotationSink = nullptr;


    /// Rotation source's rotation sinks
    std::vector<RotationSink*> mRotationSinks;


public:
    /// Constructor
    RotationSource();

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource &) = delete;

//    /**
//     * Add Rotation Sink
//     * @param rotationSink rotation sink
//     */
//    void AddSink(RotationSink *rotationSink) {mRotationSink = rotationSink; }

    /**
     * Add Rotation sink for the source
     * @param rotationSink Rotation sink for the rotation source
     */
    void AddSink(RotationSink *rotationSink) {mRotationSinks.push_back(rotationSink);}

    void UpdateRotation(double rotation);

};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
