/**
 * @file Rod.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Rod.h"

/**
 * Constructor
 * @param length The length of the rod
 * @param wid The width of the rod
 */
Rod::Rod(double length, double wid) : mLength(length), mWid(wid)
{
    mSink.SetComponent(this);

    Rectangle(0, 0, length, wid);



}

/**
 * Set Rod posiotn and the component it drives
 * @param position Position of the rod
 */
void Rod::SetPosition(wxPoint position)
{
    // Update the rotation in Polygon so it can redraw
    Component::SetPosition(position);



    mRodSource.Negotiate(this);

}
