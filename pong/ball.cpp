///////////////////////////////////////////////////////////////////////////
// Implementation of the pong ball
///////////////////////////////////////////////////////////////////////////

#include "ball.h"
/////////////////////////
// Constructors / Destructors
/////////////////////////
Ball::Ball() : Ball(0, 0, 10, 0, 0, FL_RED)
{
    //nothing to do
}


Ball::Ball(int _x, int _y, int _size, int _vx, int _vy, Fl_Color _color)
{
    x(_x);
    y(_y);
    size(_size);
    vx(_vx);
    vy(_vy);
    color(_color);
}


Ball::Ball(const Ball &other)
{
    x(other.x());
    y(other.y());
    size(other.size());
    vx(other.vx());
    vy(other.vy());
    color(other.color());
}


Ball::~Ball()
{
    //nothing to do
}

/////////////////////////
// Accessors and mutators
/////////////////////////
void 
Ball::x(int _x)
{
    this->_x = _x;
}


int 
Ball::x() const
{
    return _x;
}


void 
Ball::y(int _y)
{
    this->_y = _y;
}


int 
Ball::y() const
{
    return _y;
}


void 
Ball::size(int _size)
{
    this->_size = _size;
}


int 
Ball::size() const
{
    return _size;
}


void 
Ball::vx(int _vx)
{
    this->_vx = _vx;
}


int 
Ball::vx() const
{
    return _vx;
}

void
Ball::vy(int _vy)
{
    this->_vy = _vy;
}


int 
Ball::vy() const
{
    return _vy;
}


void 
Ball::color(Fl_Color _color)
{
    this->_color = _color;
}

Fl_Color 
Ball::color() const
{
    return _color;
}

/////////////////////////
// Ball Methods
/////////////////////////

// Update the ball for the next frame
void 
Ball::move()
{
   //update according to velocity vector 
   x(x() + vx());
   y(y() + vy());
}

// Draw the ball during an FLTK draw context
void 
Ball::draw(int xoffset, int yoffset)
{
    //draw the circle
    fl_color(_color);
    fl_pie(xoffset + x(), yoffset + y(), size(), size(), 0, 360);
}
