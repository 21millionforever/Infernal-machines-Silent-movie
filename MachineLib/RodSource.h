/**
 * @file RodSource.h
 * @author Zhendong Chen
 *
 * Rod Source helps to negotiate with rod sink
 */

#ifndef CANADIANEXPERIENCE_RODSOURCE_H
#define CANADIANEXPERIENCE_RODSOURCE_H

#include "RodSink.h"
class Rod;

/**
 * Rod Source helps to negotiate with rod sink
 */
class RodSource {
private:
    /// RodSink that rod source is connected to
    RodSink *mRodSink;

public:
    /// Constructor
    RodSource();

    /// Copy constructor (disabled)
    RodSource(const RodSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RodSource &) = delete;

    void Negotiate(Rod* rod);

    /**
     * Set rod sink
     * @param rodSink RodSink that the RodSource is connected to
     */
    void SetRodSink(RodSink *rodSink) {mRodSink = rodSink;}

};

#endif //CANADIANEXPERIENCE_RODSOURCE_H
