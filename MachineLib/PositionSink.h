/**
 * @file PositionSink.h
 * @author Zhendong Chen
 *
 * This class get position from its source
 */

#ifndef CANADIANEXPERIENCE_POSITIONSINK_H
#define CANADIANEXPERIENCE_POSITIONSINK_H

#include "Sink.h"
#include "Component.h"

/**
 * This class get position from its source
 */
class PositionSink : public Sink {
private:

public:
    /// Constructor
    PositionSink();

    /// Copy constructor (disabled)
    PositionSink(const PositionSink &) = delete;

    /// Assignment operator (disabled)
    void operator=(const PositionSink &) = delete;

//    void UpdatePosition(wxPoint position);

};

#endif //CANADIANEXPERIENCE_POSITIONSINK_H
