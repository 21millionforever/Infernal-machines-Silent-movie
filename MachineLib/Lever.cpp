/**
 * @file Lever.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Lever.h"
#include "Rod.h"

/**
 * Constructor
 * @param length The length from the middle of the lever to the end
 */
Lever::Lever(double length) : mLength(length)
{
    mRodSink.SetComponent(this);
//    Rectangle(-length/2-3, 25, length, length*0.128);

}

/**
 * Negotiate the postion between rod and another component
 * @param rod Rod
 */
void Lever::Negotiate(Rod* rod)
{
    double a = mDriveEnd;
    double x2 = GetPosition().x;
    double y2 = GetPosition().y;
    double b = rod->GetLength();
    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;
    double c = sqrt(pow(y2-y1,2) + pow(x2-x1,2));
    double d = atan2(-(y2-y1),x2-x1);
    double e = acos(( pow(b,2)+pow(c,2)-pow(a,2) ) / (2*b*c)  );
    double RodRotation_radian = d - e;
    double RodRotation = -RodRotation_radian*0.159155;
    rod->Component::SetRotation(RodRotation);


    double x3 = x1+ b*cos(-RodRotation_radian);
    double y3 = y1 + b*sin(-RodRotation_radian);
    double leverRotation_radiance = atan2( (y3-y2),(x3-x2)  );
    double leverRotation = leverRotation_radiance*0.159155;
    Component::SetRotation(leverRotation);

    double x = Component::GetPosition().x - 192 *cos(leverRotation * M_PI * 2);
    double y = Component::GetPosition().y - 180 * sin(leverRotation * M_PI * 2);

    mRotationSource.UpdateRotation(leverRotation);
    mPositionSource.UpdatePosition(wxPoint(x,y));

}


