/**
 * @file Sink.h
 * @author Zhendong Chen
 *
 * Class that represent a sink
 */

#ifndef CANADIANEXPERIENCE_SINK_H
#define CANADIANEXPERIENCE_SINK_H

#include "Component.h"

/**
 * Class that represent a sink
 */
class Sink {
private:
    /// A pointer to a component object
    Component* mComponent;

public:

    /**
     * Set component
     * @param component Component
     */
    void SetComponent(Component* component) {
        mComponent = component;
    }

    /**
     * Get component
     * @return Component
     */
    Component* GetComponent(){ return mComponent; }




};

#endif //CANADIANEXPERIENCE_SINK_H
