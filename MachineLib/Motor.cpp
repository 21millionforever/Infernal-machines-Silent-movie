/**
 * @file Motor.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Motor.h"

/**
 * Conxtructor
 * @param imagesDir1 The image for the wheel
 * @param imagesDir2 The image for the body
 * @param wheelWid The width of the wheel
 * @param bodyWid The width of the body
 */
Motor::Motor(const std::wstring& imagesDir1,const std::wstring& imagesDir2, int wheelWid, int bodyWid)
{
    this->CenteredSquare(wheelWid);
    this->SetImage(imagesDir1);

    mBody->Rectangle(-bodyWid/2, -1, bodyWid, bodyWid);
    mBody->SetImage(imagesDir2);

}

/**
 * Draw the motor
 * @param graphics The context we are drawing on
 * @param x The x coordinate
 * @param y The y coordinate
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::Draw(graphics, x, y-50);
    mBody->DrawPolygon(graphics,x+mBodyPosition.x, y+mBodyPosition.y);

}

/**
 * Set time for motor
 * @param time Time that represents rotation
 */
void Motor::SetTime(double time)
{
    double rotation = mSpeed * time;
    SetRotation(rotation);

}

/**
 * Set rotation for motor's polygon to redraw and pass the rotation to
 * its sink
 * @param rotation
 */
void Motor::SetRotation(double rotation)
{
    // Update the rotation in Polygon so it can redraw
    Component::SetRotation(rotation);

    // Tell the sink about the rotation
    mSource.UpdateRotation(rotation);
}

/**
 * Set speed for motor
 * @param speed Speed for the motor
 */
void Motor::SetSpeed(double speed)
{
    mSpeed = speed;
}



