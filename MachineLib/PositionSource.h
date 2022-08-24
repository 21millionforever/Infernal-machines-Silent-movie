/**
 * @file PositionSource.h
 * @author Zhendong Chen
 *
 * Class that represents a position source that drives its sink
 */

#ifndef CANADIANEXPERIENCE_POSITIONSOURCE_H
#define CANADIANEXPERIENCE_POSITIONSOURCE_H

#include "PositionSink.h"

#include "Component.h"
#include "Rod.h"

/**
 * Class that represents a position source that drives its sink
 */
class PositionSource {
private:

    /// A pointer to a rod
    std::shared_ptr<Component> mComponent;


public:
    /// Constructor
    PositionSource();

    /// Copy constructor (disabled)
    PositionSource(const PositionSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const PositionSource &) = delete;


    void UpdatePosition(wxPoint position);

    /**
     * Set a pointer to a rod
     * @param component rod component
     */
    void AddComponent(std::shared_ptr<Rod> component) {
        mComponent = component;
    }

};

#endif //CANADIANEXPERIENCE_POSITIONSOURCE_H
