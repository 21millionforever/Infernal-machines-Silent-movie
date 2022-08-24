/**
 * @file Arm.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Arm.h"

/**
 * Constructor
 * @param length The length of the arm
 */
Arm::Arm(int length) : mLength(length)
{
    mSink.SetComponent(this);

    AddPoint(-7,7);
    AddPoint(-7,-7);
    AddPoint(length+5,-7);
    AddPoint(length+5,7);
}

/**
 * Draw the arm
 * @param graphics the context we are drawing on
 * @param x the x coordinate of the arm
 * @param y the y coordinate of the arm
 */
void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y);

}
/**
 * Set the rotation for the polygon to draw and
 * also tell the position to the component it drives to move
 * @param rotation Arm's rotation
 */
void Arm::SetRotation(double rotation)
{
    // Update the rotation in Polygon so it can redraw
    Component::SetRotation(rotation);

    // Tell the sink about the position rotation
    double x = GetPosition().x + mLength * cos(rotation * M_PI * 2);
    double y = GetPosition().y + mLength * sin(rotation * M_PI * 2);

    mPositionSource.UpdatePosition(wxPoint(x,y));
}
