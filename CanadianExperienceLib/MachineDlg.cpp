///**
// * @file MachineDlg.cpp
// * @author Zhendong Chen
// */
//
//#include "pch.h"
//#include <wx/xrc/xmlres.h>
//#include <wx/valnum.h>
//#include "MachineDlg.h"
//
//using namespace std;
//
///**
// * Constructor
// * @param parent  Pointer to wxFrame object, the main frame for the application
// * @param machineAdapterOne The first Actual machine
// * @param machineAdapterTwo The second Actual machine
// */
//MachineDlg::MachineDlg(wxWindow* parent,std::shared_ptr<Drawable> machineAdapterOne, std::shared_ptr<Drawable> machineAdapterTwo) : mMachineAdapterOne(machineAdapterOne), mMachineAdapterTwo(machineAdapterTwo)
//{
//    wxXmlResource::Get()->LoadDialog(this, parent, L"MachineDlg");
//
//    Bind(wxEVT_BUTTON, &MachineDlg::OnOK, this, wxID_OK);
//
//    auto machineNumCtrl = XRCCTRL(*this, "MachineDlgMachineNum", wxTextCtrl);
//    wxIntegerValidator<int> machineNumValidator(&mMachineNum);
//    machineNumValidator.SetRange(1, 2);
//    machineNumCtrl->SetValidator(machineNumValidator);
//
//    auto machineStartFrameCtrl = XRCCTRL(*this, "MachineDlgStartFrame", wxTextCtrl);
//    wxIntegerValidator<int> machineStartFrameValidator(&mMachineStartFrame);
//    machineNumValidator.SetRange(1, 10000);
//    machineStartFrameCtrl->SetValidator(machineStartFrameValidator);
//
//}
//
///**
// * Handle the OK button press event
// * @param event Button press event
// */
//void MachineDlg::OnOK(wxCommandEvent& event)
//{
//    if ( Validate() && TransferDataFromWindow() )
//    {
//        EndModal(wxID_OK);
//        if(mMachineNum == 1)
//        {
//            mMachineAdapterOne->SetStartFrame(mMachineStartFrame);
//        }
//        else if (mMachineNum == 2)
//        {
//            mMachineAdapterTwo->SetStartFrame(mMachineStartFrame);
//        }
//
//    }
//}




