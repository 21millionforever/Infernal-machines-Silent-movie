/**
 * @file RotationSource.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "RotationSource.h"

/**
 * Constructor
 */
RotationSource::RotationSource()
{
//    mRotationSink = nullptr;

}

/**
 * Update rotation sink's rotation
 * @param rotation
 */
void RotationSource::UpdateRotation(double rotation)
{
//    if (mRotationSink != nullptr)
//        mRotationSink->UpdateRotation(rotation);



    if(mRotationSinks.size() >= 1)
    {
        for(auto sink : mRotationSinks)
        {
            sink->UpdateRotation(rotation);
        }
    }
}
