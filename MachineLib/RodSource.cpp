/**
 * @file RodSource.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "RodSource.h"
#include "Rod.h"

/**
 * Constructor
 */
RodSource::RodSource()
{

}

/**
 * Negotiate between rod source and sink
 * @param rod
 */
void RodSource::Negotiate(Rod* rod)
{
    if(mRodSink != nullptr)
    {
        mRodSink->Negotiate(rod);
    }


}
