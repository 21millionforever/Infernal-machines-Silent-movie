/**
 * @file Piston.h
 * @author Zhendong Chen
 *
 * Class that represents a piston
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "RodSink.h"
class Rod;
#include "Component.h"

/**
 * Class that represents a piston
 */
class Piston : public Component {
private:
    /// Piston is a rod sink
    RodSink mRodSink;

public:
    Piston();

    /**
     * Get Rod sink
     * @return Rod sink
     */
    RodSink *GetRodSink() {return &mRodSink;}

    void Negotiate(Rod *rod) override;

};

#endif //CANADIANEXPERIENCE_PISTON_H
