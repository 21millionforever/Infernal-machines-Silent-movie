/**
 * @file MachineAdapter.h
 * @author Zhendong Chen
 *
 * An adapter class that add machine to Canadian experience
 */

#ifndef CANADIANEXPERIENCE_MACHINEADAPTER_H
#define CANADIANEXPERIENCE_MACHINEADAPTER_H

#include "Drawable.h"
#include "StartFrame.h"
#include "../MachineLib/Machine.h"
#include "ViewEdit.h"
#include "../MachineLib/MachineFactory.h"

/**
 * A class that is inherited from Drawable and draw the machine
 */
class MachineAdapter : public Drawable {
private:

    /// The actual machine we are going to draw
    std::shared_ptr<Machine> mMachine;

    /// The start frame for the machine
    double mStartFrame=0;

public:
    MachineAdapter(const std::wstring &name, std::wstring imagesDir);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(wxPoint location);

    bool HitTest(wxPoint pos) override;

    void SetMachineNumber(int machine);


    void  OnMachine(wxFrame* parent,ViewEdit *viewEdit) override;

    /**
     * Set the start frame for the machine
     * @param startFrame frame that starts to run
     */
    void SetStartFrame(double startFrame) {mStartFrame = startFrame;}



};

#endif //CANADIANEXPERIENCE_MACHINEADAPTER_H
