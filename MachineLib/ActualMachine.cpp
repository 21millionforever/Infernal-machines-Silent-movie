/**
 * @file ActualMachine.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "ActualMachine.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"

/**
 * Constructor
 * @param imagesDir The image directory
 */
ActualMachine::ActualMachine(std::wstring imagesDir) : mImagesDir(imagesDir)
{
    SetMachineNumber(2);
}

/**
 * Set the location for the actual machine
 * @param location machine's new location
 */
void ActualMachine::SetLocation(wxPoint location)
{
    mLocation = location;
}

/**
 * Get the location for the actual machine
 * @return machine's location
 */
wxPoint ActualMachine::GetLocation()
{
    return mLocation;
}

/**
 * Draw the machine
 * @param graphics the graphic that we are drawing on
 */
void ActualMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mWorkingMachine->Draw(graphics, mLocation.x, mLocation.y);

}

/**
 * Set the current frame for the machine
 * @param frame the current frame
 */
void ActualMachine::SetMachineFrame(int frame)
{

    mCurrFrame = frame;
    double time = frame / mFrameRate * mSpeed;
    if(mWorkingMachine != NULL)
        mWorkingMachine->SetTime(time);

}

/**
 * Set the Frame rate
 * @param rate
 */
void ActualMachine::SetFrameRate(double rate)
{
    mFrameRate = rate;
}

/**
 * Set the speed for the actual machine
 * @param speed The speed of the machine
 */
void ActualMachine::SetSpeed(double speed)
{
    mSpeed = speed;
}

/**
 * Set the machine number
 * @param machine machine number
 */
void ActualMachine::SetMachineNumber(int machine)
{
    if(machine != 1 and machine !=2)
        mMachineNumber = 1;
    else
        mMachineNumber = machine;

    if(mMachineNumber == 1)
    {
        Machine1Factory machine1Factory;
        mWorkingMachine = machine1Factory.Create(mImagesDir);
    }

    else if (mMachineNumber == 2)
    {
        Machine2Factory machine2Factory;
        mWorkingMachine = machine2Factory.Create(mImagesDir);
    }



}

/**
 * Get the machine number
 * @return current machine number
 */
int ActualMachine::GetMachineNumber()
{
    return mMachineNumber;
}

/**
 * Get the current time
 * @return the current time
 */
double ActualMachine::GetMachineTime()
{
    double time = mCurrFrame / mFrameRate;
    return time;
}
