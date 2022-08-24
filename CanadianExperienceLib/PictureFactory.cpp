/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineAdapter.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();


    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);


    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Machine
    auto machineAdapterOne = make_shared<MachineAdapter>(L"MachineAdapterOne",imagesDir);
    auto machineAdapterTwo = make_shared<MachineAdapter>(L"MachineAdapterTwo",imagesDir);
    machineAdapterOne->SetMachineNumber(1);
    machineAdapterOne->SetStartFrame(510);

    machineAdapterTwo->SetMachineNumber(2);
    machineAdapterTwo->SetStartFrame(45);

    auto machine = make_shared<Actor>(L"MachineOne");
    machine->SetClickable(false);

    machine->AddDrawable(machineAdapterOne);
    machine->AddDrawable(machineAdapterTwo);
    machine->SetRoot(machineAdapterOne);
    machineAdapterOne->SetLocation(wxPoint(250,500));
    machineAdapterTwo->SetLocation(wxPoint(700,500));
    picture->AddActor(machine);




    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(890, 520));
    picture->AddActor(sparty);




    return picture;
}

