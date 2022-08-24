/**
 * @file Rod.h
 * @author Zhendong Chen
 *
 * Class that represent a rod
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "PositionSink.h"
#include "RodSink.h"
#include "RodSource.h"

/**
 * Class that represent a rod
 */
class Rod : public Component {
private:

    /// The length of the rod
    double mLength;

    /// The width of the rod
    double mWid;

    /// Rod is a position sink
    PositionSink mSink;


    /// Rod is a source
    RodSource mRodSource;





public:
    Rod(double length, double wid);

    /// Copy constructor/disabled
    Rod(const Rod&) = delete;

    /// Assignment operator/disabled
    void operator=(const Rod&) = delete;


    void SetPosition(wxPoint position) override;


    /**
     * Set Rod Sink
     * @param rodSink Rod Sink
     */
    void SetRodSink(RodSink* rodSink) { mRodSource.SetRodSink(rodSink);}

    /**
     * Get the lnegth of the rod
     * @return
     */
    double GetLength() {return mLength;}






};

#endif //CANADIANEXPERIENCE_ROD_H
