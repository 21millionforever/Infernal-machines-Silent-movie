/**
 * @file RodSink.h
 * @author Zhendong Chen
 *
 * RodSink for the components
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H

#include "Sink.h"

class Lever;

/**
 * Rod sink for components
 */
class RodSink : public Sink {
private:


public:
    RodSink();

    void Negotiate(Rod* rod);

};

#endif //CANADIANEXPERIENCE_RODSINK_H
