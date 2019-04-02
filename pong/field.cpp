#include "field.h"

/////////////////////////
// Constructor
/////////////////////////
Field::Field(int _x, int _y, int _w, int _h) : Fl_Widget(_x,_y,_w,_h)
{
   reset_ball();

   //Run the game
   unpause();
}

/////////////////////////
// Methods
/////////////////////////

//pause and unpaused
void 
Field::pause()
{
    _paused = true;
}

void 
Field::unpause()
{
    _paused = false;
}

//check if it is paused
bool 
Field::is_paused() const
{
    return _paused;
}


//Advance to the next frame
void 
Field::update()
{
    if(is_paused()) {
        return;
    }

    //check for ball collisions
    if(_ball.vx() > 0 and _ball.x() + _ball.vx() + _ball.size() >= w()) {
        //leaving the edge
        reset_ball();
    } else if(_ball.x() + _ball.vx() <= 0) {
        //leaving the edge
        reset_ball();
    }
    if(_ball.vy() > 0 and _ball.y() + _ball.vy() + _ball.size() >= h()) {
        _ball.vy(-_ball.vy()-1); //bounce
    } else if(_ball.y() + _ball.vy() <= 0) {
        _ball.vy(-_ball.vy()+1); //bounce
    }
    _ball.move();
}

//Draw the widget
void 
Field::draw()
{
    fl_color(FL_BLACK);
    fl_rectf(x(), y(), w(), h());
    _ball.draw(x(), y());
}


//Event handler
int
Field::handle(int event)
{
    switch(event) {
    case FL_RELEASE:
        if(is_paused()) {
            unpause();
        } else {
            pause();
        }
        return 1;
        break;
    }

    return Fl_Widget::handle(event);
}


//reset the ball
void 
Field::reset_ball()
{
   //position the ball
   _ball.size((int)(w() * .02 + 1));
   _ball.x(w()/2 - _ball.size()/2);
   _ball.y(h()/2 - _ball.size()/2);
   _ball.vx(rand()%11-5);
   _ball.vy(rand()%11-5);
}
