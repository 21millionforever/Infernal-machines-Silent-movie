/**
 * @file ActualMachine.h
 * @author Zhendong Chen
 *
 * The actual Machine
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

#include "Machine.h"
#include "WorkingMachine.h"

/**
 * ActualMachine contains working machines
 */
class ActualMachine : public Machine {
private:
    /// The location of the machine
    wxPoint mLocation;

    /// The current machine animation frame
    int mCurrFrame;

    /// the frame rate in frames per second
    double mFrameRate;

    /// The speed of the machine
    double mSpeed;

    /// The machine number
    int mMachineNumber;

    /// The working machine we are drawing
    std::shared_ptr<WorkingMachine> mWorkingMachine;

    /// The images directory
    std::wstring mImagesDir;


public:
    /// Constructor
    ActualMachine(std::wstring imagesDir);

    /// Copy constructor/disabled
    ActualMachine(const ActualMachine&) = delete;

    /// Assignment operator/disabled
    void operator=(const ActualMachine&) = delete;

    void SetLocation(wxPoint location) override;

    wxPoint GetLocation() override;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetMachineFrame(int frame) override;

    void SetFrameRate(double rate) override;

    void SetSpeed(double speed) override;

    void SetMachineNumber(int machine) override;

    int GetMachineNumber() override;

    double GetMachineTime() override;

//    void SetWorkingMachine(std::shared_ptr<WorkingMachine> workingMachine);



};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
