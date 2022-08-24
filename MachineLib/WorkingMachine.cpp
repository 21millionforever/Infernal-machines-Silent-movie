/**
 * @file WorkingMachine.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "WorkingMachine.h"
#include "Motor.h"

/**
 * Constructor
 * @param machine Machien number
 */
WorkingMachine::WorkingMachine(int machine) : mMachine(machine)
{

}

/**
 * Draw the working machine with all the component
 * @param graphics The context we are drawing on
 * @param x The x coordinate
 * @param y The y coordinate
 */
void WorkingMachine::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    for (auto component : mComponentInOrder)
    {
        component->Draw(graphics, x, y);
    }

}

/**
 * Set time for the motor
 * @param time time
 */
void WorkingMachine::SetTime(double time)
{

    if (mMotor != NULL)
        mMotor->SetTime(time);
}

/**
 * Add component to the machine
 * @param component Component that makes up the working machine
 */
void WorkingMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponentInOrder.push_back(component);

    component->SetWorkingMachine(this);
}


//int WorkingMachine::GetMachine() const
//{
//    return mMachine;
//}
//
//void WorkingMachine::SetMachine(int machine)
//{
//    mMachine = machine;
//}
