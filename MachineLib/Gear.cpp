/**
 * @file Gear.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Gear.h"

/**
 * Constructor
 * @param radius The radius of the Gear
 * @param numTeeth The number of teeth for the Gear
 */
Gear::Gear(double radius, int numTeeth) : mRadius(radius), mNumTeeth(numTeeth)
{
    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }

    mSink.SetComponent(this);

}


/**
 * Draw the gear
 * @param graphics The context we are drawing on
 * @param x The x coordinate of the gear
 * @param y The y coordinate of the gear
 */
void Gear::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);

}

/**
 * Set the rotation for the polygon to draw and
 * also tell the rotation to the component it drives to rotate
 * @param rotation
 */
void Gear::SetRotation(double rotation)
{
    // Update the rotation in Polygon so it can redraw
    Component::SetRotation(rotation);

    // Tell the sink about the rotation
    mSource.UpdateRotation(rotation);


}


/**
 * Set the speed for gear based on other gears it's connected to
 * @param gear The gear that drives this to rotate
 * @param phase The phrase of the rotation
 */
void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();

    mSource.AddSink(sink);
    sink->SetSpeed(-(double)mNumTeeth / (double)gear->mNumTeeth);
    sink->SetPhase(phase);
}