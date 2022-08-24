/**
 * @file Shape.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Shape.h"

/**
 * Constructor
 */
Shape::Shape()
{
    mSink.SetComponent(this);
}

