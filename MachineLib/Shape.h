/**
 * @file Shape.h
 * @author Zhendong Chen
 *
 *  Class that represent a shape
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "RotationSink.h"

#include "Component.h"

/**
 * Class that represent a shape
 */
class Shape : public Component {
private:
    /// Shape is a rotation sink
    RotationSink mSink;

public:
    /// Constructor
    Shape();

    /// Copy constructor/disabled
    Shape(const Shape&) = delete;

    /// Assignment operator/disabled
    void operator=(const Shape&) = delete;

    /**
     * Get rotation sink
     * @return Rotation sink
     */
    RotationSink *GetSink() {return &mSink;}


};

#endif //CANADIANEXPERIENCE_SHAPE_H
