/**
 * @file RotationSink.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "RotationSink.h"

/**
 * Constructor
 */
RotationSink::RotationSink()
{

}


/**
 * Update rotation for component that is connected to this RotationSink
 * @param rotation
 */
void RotationSink::UpdateRotation(double rotation)
{
    GetComponent()->SetRotation(rotation * mSpeed + mPhase);
}
