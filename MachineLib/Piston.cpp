/**
 * @file Piston.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Piston.h"
#include "Rod.h"
/**
 * Constructor
 */
Piston::Piston()
{
    mRodSink.SetComponent(this);
}

/**
 * Negotiate between piston and rod
 * @param rod
 */
void Piston::Negotiate(Rod* rod)
{
    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;

    double x2 = GetPosition().x;
    double a = rod->GetLength();

    double wid = x2-x1;
    double b = sqrt(pow(a,2)-pow(wid,2));

    double c = asin((x2-x1)/a );
    double d_radiance = M_PI / 2 - c;
    double d = d_radiance * 0.159155;
    double y2 = y1+b;

    rod->Component::SetRotation(d);

    wxPoint position = wxPoint(x2,y2);
    SetPosition(position);

}
