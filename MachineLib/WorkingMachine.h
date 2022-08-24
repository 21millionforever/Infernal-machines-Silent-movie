/**
 * @file WorkingMachine.h
 * @author Zhendong Chen
 *
 * Working machine we are making
 */

#ifndef CANADIANEXPERIENCE_WORKINGMACHINE_H
#define CANADIANEXPERIENCE_WORKINGMACHINE_H
#include "Component.h"

class Motor;

/**
 * Working machine we are making
 */
class WorkingMachine {
private:
    /// Motor that is part of the WorkingMachine
    std::shared_ptr<Motor> mMotor;

    /// Components in drawing order
    std::vector<std::shared_ptr<Component>> mComponentInOrder;

    /// The number of the machine
    int mMachine;



public:
    WorkingMachine(int machine);

    /// Destructor
    virtual ~WorkingMachine() = default;

    /// Copy constructor/disabled
    WorkingMachine(const WorkingMachine&) = delete;

    /// Assignment operator/disabled
    void operator=(const WorkingMachine&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    void SetTime(double time);

    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Set motor
     * @param motor Motor
     */
    void SetMotor(std::shared_ptr<Motor> motor) { mMotor = motor;}

};

#endif //CANADIANEXPERIENCE_WORKINGMACHINE_H
