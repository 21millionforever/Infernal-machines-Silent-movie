///**
// * @file MachineDlg.h
// * @author Zhendong Chen
// *
// * Class that implements a dialog box for selecting start frame
// */
//
//#ifndef CANADIANEXPERIENCE_MACHINEDLG_H
//#define CANADIANEXPERIENCE_MACHINEDLG_H
//
//#include "MachineAdapter.h"
//
//
///**
// * Dialog box for selecting start frame
// */
//class MachineDlg final : public wxDialog {
//private:
//
//
//    /// The first Actual machine
//    std::shared_ptr<Drawable> mMachineAdapterOne;
//
//    /// The second Actual machine
//    std::shared_ptr<Drawable> mMachineAdapterTwo;
//
//    /// which machine we are setting the start frame
//    int mMachineNum = 1;
//
//    /// The start frame of the machine
//    int mMachineStartFrame = 0;
//
//    void OnOK(wxCommandEvent& event);
//
//public:
//    MachineDlg(wxWindow *parent, std::shared_ptr<Drawable> machineAdapterOne, std::shared_ptr<Drawable> machineAdapterTwo);
//
//
//
//};
//
//#endif //CANADIANEXPERIENCE_MACHINEDLG_H
