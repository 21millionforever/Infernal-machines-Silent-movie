/**
 * @file StartFrame.h
 * @author Zhendong Chen
 *
 * This class help to set the start frame
 */

#ifndef CANADIANEXPERIENCE_STARTFRAME_H
#define CANADIANEXPERIENCE_STARTFRAME_H

#include "ViewEdit.h"
/**
 * Help to set the start frame for machine
 */
class StartFrame {
private:
    /// start frame for machine
    int mStartFrame;

    /// the status of setting start frame for machine
    bool mIsStartFrameSet = false;

public:
    virtual ~StartFrame() {}


    /**
     * Get start frame for machine
     * @return start frame
     */
    int GetStartFrame() {return mStartFrame;}

    void SetStartFrame(int startFrame);

    /**
     * Get the status of whether machine's start frame is set or not
     * @return the status of setting start frame
     */
    bool GetIsStartFrameSet() {return mIsStartFrameSet; }

    /**
     * handle machine changing dialog
     * @param parent The parent of ViewEdit
     * @param viewEdit ViewEdit
     */
    virtual void  OnMachine(wxFrame* parent, ViewEdit *viewEdit) {}




};

#endif //CANADIANEXPERIENCE_STARTFRAME_H
