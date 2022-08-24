/**
 * @file Component.h
 * @author Zhendong Chen
 *
 * We use components to make up a machine
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H
class WorkingMachine;
#include "Polygon.h"
class Rod;

class RotationSource;

/**
 * We use components to make up a machine
 */
class Component : public Polygon{
private:
    /// The position of the component
    wxPoint mPosition;

    /// The working machine we are going to create
    WorkingMachine *mWorkingMachine;

public:
    /// Destructor
    virtual ~Component() {}

    Component();

    /// Copy constructor/disabled
    Component(const Component&) = delete;

    /// Assignment operator/disabled
    void operator=(const Component&) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    virtual void SetRotation(double rotation);

    virtual void SetPosition(wxPoint Point);

    /**
     * Get the position of the component
     * @return the position of the component
     */
    virtual wxPoint GetPosition() {return mPosition;}

    virtual void SetWorkingMachine(WorkingMachine* workingMachine);

    /**
     * Negotiate position and rotation between Rod and other components
     * like Lever and piston
     * @param rod Rod
     */
    virtual void Negotiate(Rod *rod) {}


};

#endif //CANADIANEXPERIENCE_COMPONENT_H
