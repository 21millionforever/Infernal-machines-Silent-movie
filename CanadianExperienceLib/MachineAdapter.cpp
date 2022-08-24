/**
 * @file MachineAdapter.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "MachineAdapter.h"
#include "Timeline.h"
#include "Actor.h"
#include "Picture.h"
#include "../MachineLib/MachineDialog.h"

using namespace std;

/**
 * Constructor
 * @param name The name of the drawable adapter
 * @param imagesDir image resource path
 */
MachineAdapter::MachineAdapter(const wstring& name, std::wstring imagesDir) : Drawable(name)
{
    MachineFactory factory(imagesDir);
    mMachine = factory.CreateMachine();
    mMachine->SetLocation(wxPoint(500, 500));
    mMachine->SetMachineFrame(600);
    mMachine->SetFrameRate(20);
    mMachine->SetSpeed(1);

}

/**
 * Draw the machine
 * @param graphics context we are drawing on
 */
void MachineAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    double currentFrame = GetAngleChannel()->GetTimeline()->GetCurrentFrame();
    if(currentFrame > mStartFrame)
        mMachine->SetMachineFrame(currentFrame-mStartFrame);
    else
        mMachine->SetMachineFrame(0);



    mMachine->DrawMachine(graphics);
}

/**
 * Set the location of the machine
 * @param location location of the machine
 */
void MachineAdapter::SetLocation(wxPoint location)
{
    mMachine->SetLocation(location);


}

/**
 * Test to see if we clicked on the machine.
 * @param pos Position to test
 * @return False
 */
bool MachineAdapter::HitTest(wxPoint pos)
{
    return false;
}

/**
 * Set the machine number
 * @param machine Actual machine
 */
void MachineAdapter::SetMachineNumber(int machine)
{
    mMachine->SetMachineNumber(machine);
}

/**
 * handle machine changing dialog
 * @param parent The parent of ViewEdit
 * @param viewEdit ViewEdit
 */
void MachineAdapter::OnMachine(wxFrame* parent, ViewEdit *viewEdit)
{
    MachineDialog dlg(parent, mMachine);
    if (dlg.ShowModal() == wxID_OK)
    {
        viewEdit->UpdateObserver();
    }
}




