/**
 * @file StartFrame.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "StartFrame.h"

/**
 * Set start frame for machine
 * @param startFrame start frame
 */
void StartFrame::SetStartFrame(int startFrame)
{
    mStartFrame = startFrame;
    mIsStartFrameSet = true;
}
