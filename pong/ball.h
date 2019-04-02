///////////////////////////////////////////////////////////////////////////
// File: ball.h
// Purpose: Class definition of a representation of a ball
///////////////////////////////////////////////////////////////////////////
#include <Fl/fl_draw.H>
#ifndef BALL_H
#define BALL_H
class Ball
{
public:
    /////////////////////////
    // Constructors / Destructors
    /////////////////////////
    Ball();  
    Ball(int _x, int _y, int _size, int _vx, int _vy, Fl_Color _color);
    Ball(const Ball &other);
    virtual ~Ball();

    /////////////////////////
    // Accessors and mutators
    /////////////////////////
    virtual void x(int _x);
    virtual int x() const;

    virtual void y(int _y);
    virtual int y() const;

    virtual void size(int _size);
    virtual int size() const;

    virtual void vx(int _vx);
    virtual int vx() const;

    virtual void vy(int _vy);
    virtual int vy() const;

    virtual void color(Fl_Color _color);
    virtual Fl_Color color() const;

    /////////////////////////
    // Ball Methods
    /////////////////////////

    // Update the ball for the next frame
    virtual void move();

    // Draw the ball during an FLTK draw context
    virtual void draw(int xoffset, int yoffset);

private:
    int _x;  //x coordinate of the ball
    int _y;  //y coordinate of the ball
    int _size;  //size of the ball
    int _vx; //x velocity
    int _vy; //y velocity
    Fl_Color _color;  //color of the ball
};
#endif
