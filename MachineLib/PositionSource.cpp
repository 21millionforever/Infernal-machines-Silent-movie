/**
 * @file PositionSource.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "PositionSource.h"

/**
 * Constructor
 */
PositionSource::PositionSource()
{

}


/**
 * Update rod's position
 * @param position rod's position
 */
void PositionSource::UpdatePosition(wxPoint position)
{

    if (mComponent != nullptr)
    {
        mComponent->SetPosition(position);
    }

}

