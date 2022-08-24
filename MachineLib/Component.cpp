/**
 * @file Component.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Component.h"

/**
 * Constructor
 */
Component::Component()
{

}

/**
 * Draw the component
 * @param graphics The context we are drawing on
 * @param x The x coordinate of the component
 * @param y The y coordinate of the component
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Polygon::DrawPolygon(graphics,x+mPosition.x, y+mPosition.y);

}

/**
 * Set Rotation for the component
 * @param rotation component's rotation
 */
void Component::SetRotation(double rotation)
{
    Polygon::SetRotation(rotation);
}

/**
 * Set the position of the component
 * @param Point the position of the component
 */
void Component::SetPosition(wxPoint Point)
{
    mPosition = Point;

}
/**
  * Set the working Machine
  * @param workingMachine the machine we are creating
  */
void Component::SetWorkingMachine(WorkingMachine* workingMachine)
{
    mWorkingMachine = workingMachine;
}


