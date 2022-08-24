/**
 * @file RodSink.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "RodSink.h"
#include "Rod.h"
#include "Lever.h"

/**
 * Constructor
 */
RodSink::RodSink()
{


}

/**
 * Negotiate between rod and other components
 * @param rod Rod
 */
void RodSink::Negotiate(Rod* rod)
{
    if (GetComponent() != nullptr)
    {
        GetComponent()->Negotiate(rod);
    }

}

