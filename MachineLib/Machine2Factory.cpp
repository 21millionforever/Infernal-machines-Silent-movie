/**
 * @file Machine2Factory.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Machine2Factory.h"
#include "WorkingMachine.h"
#include "Motor.h"
#include "Shape.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"
#include "Piston.h"

using namespace std;

/**
 * This is a factory method that creates machine 2.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<WorkingMachine> Machine2Factory::Create(std::wstring imagesDir)
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<WorkingMachine>(2);

    auto wire = make_shared<Shape>();
    wire->Rectangle(0,0,10,50);
    wire->SetColor(wxColour(90, 114, 115));
    wire->SetPosition(wxPoint(-55,-40));
    machine->AddComponent(wire);

    // The motor
    auto motor = make_shared<Motor>(imagesDir + L"/electric-wheel.png",imagesDir+ L"/electric_box.png",50,150);
    motor->SetPosition(wxPoint(-50, -38));
    motor->SetBodyPosition(wxPoint(-50,50));
    motor->SetSpeed(1.0);
    machine->SetMotor(motor);
    machine->AddComponent(motor);

    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(imagesDir + L"/gold.png");
    gear1->SetPosition(wxPoint(-50, -38 - 100/ 2));
    machine->AddComponent(gear1);
    motor->GetSource()->AddSink(gear1->GetSink());


    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(imagesDir + L"/gold.png");
    gear2->SetPosition(wxPoint(gear1->GetPosition().x + 55, gear1->GetPosition().y));
    machine->AddComponent(gear2);
    gear1->Drive(gear2, 0.1);


    //Test
    auto gear3 = make_shared<Gear>(40, 20);
    gear3->SetImage(imagesDir + L"/gold.png");
    gear3->SetPosition(wxPoint(gear2->GetPosition().x + 55, gear2->GetPosition().y-52));
    machine->AddComponent(gear3);
    gear2->Drive(gear3, 0.1);

    auto gear4 = make_shared<Gear>(30, 20);
    gear4->SetImage(imagesDir + L"/gold.png");
    gear4->SetPosition(wxPoint(gear3->GetPosition().x + 50, gear3->GetPosition().y-40));
    machine->AddComponent(gear4);
    gear3->Drive(gear4, 0.1);

    auto gear5 = make_shared<Gear>(44, 30);
    gear5->SetImage(imagesDir + L"/gold.png");
    gear5->SetPosition(wxPoint(gear4->GetPosition().x-50 , gear4->GetPosition().y-45));
    machine->AddComponent(gear5);
    gear4->Drive(gear5, 0.1);


    auto dolphin = make_shared<Shape>();
    dolphin->AddPoint(-100,0);
    dolphin->AddPoint(-100,-100);
    dolphin->AddPoint(50,-100);
    dolphin->AddPoint(50,0);
    dolphin->SetPosition(wxPoint(70,-300));

    dolphin->SetImage(imagesDir + L"/dolphin.png");
    gear5->GetSource()->AddSink(dolphin->GetSink());



    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(10);

    arm->SetImage(imagesDir + L"/arm1.png");
    arm->SetPosition(gear2->GetPosition());
    machine->AddComponent(arm);
    gear2->GetSource()->AddSink(arm->GetSink());


    // The ship
    auto ship = make_shared<Lever>(400);
    ship->SetPosition(wxPoint(-50, -232));
    ship->SetImage(imagesDir + L"/Untitled_Artwork.png");
    ship->SetDriveEnd(100);
    ship->Rectangle(0,10,200,100);



    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(150,7);
    int gray = 50;
    rod1->SetColor(wxColour(90, 114, 115));
    machine->AddComponent(rod1);

    arm->GetPositionSource()->AddComponent(rod1);
    rod1->SetRodSink(ship->GetRodSink());

    // The ocean
    auto ocean = make_shared<Shape>();
    int wid = 550;
    ocean->Rectangle(-110,-200,340,100);
    ocean->SetImage(imagesDir + L"/ocean3.png");


    auto stage = make_shared<Shape>();
    stage->Rectangle(-140,-150,380,300);
    stage->SetImage(imagesDir + L"/stage.png");

    auto storm = make_shared<Shape>();
    storm->Rectangle(-120,-150,340,300);
    storm->SetImage(imagesDir + L"/storm.png");



    // sailer
    auto sailer = make_shared<Shape>();
    sailer->AddPoint(25, -10);
    sailer->AddPoint(25, -210);
    sailer->AddPoint(225, -210);
    sailer->AddPoint(225, -10);
    sailer->SetImage(imagesDir + L"/Sailer.png");
    sailer->SetPosition(ship->GetPosition());
    ship->GetRotationSource()->AddSink(sailer->GetSink());


    // seagull
    auto seagull = make_shared<Shape>();
    seagull->AddPoint(0, -10);
    seagull->AddPoint(0, -50);
    seagull->AddPoint(70, -50);
    seagull->AddPoint(70, -10);
    seagull->SetImage(imagesDir + L"/seagull.png");
    seagull->SetPosition(wxPoint(ship->GetPosition().x,ship->GetPosition().y-150));
    ship->GetRotationSource()->AddSink(seagull->GetSink());





    machine->AddComponent(storm);
    machine->AddComponent(dolphin);
    machine->AddComponent(sailer);
    machine->AddComponent(ship);
    machine->AddComponent(ocean);
    machine->AddComponent(seagull);
    machine->AddComponent(stage);







    return machine;
}

