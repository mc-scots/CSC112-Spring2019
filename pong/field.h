///////////////////////////////////////////////////////////////////////////
// File: field.h 
// Purpose: A definition of a pong play field class
///////////////////////////////////////////////////////////////////////////
#include <Fl/Fl.H>
#include <Fl/Fl_Widget.H>
#include "ball.h"
#ifndef FIELD_H
#define FIELD_H
class Field : public Fl_Widget
{
public:
    /////////////////////////
    // Constructor
    /////////////////////////
    Field(int _x, int _y, int _w, int _h);

    /////////////////////////
    // Methods
    /////////////////////////

    //pause and unpaused
    virtual void pause();
    virtual void unpause();

    //check if it is paused
    virtual bool is_paused() const;

    //Advance to the next frame
    virtual void update();

    //Draw the widget
    virtual void draw();

    //Event handler
    virtual int handle(int event);

    //reset the ball
    virtual void reset_ball();

private:
    Ball _ball;
    bool _paused;
};
#endif
