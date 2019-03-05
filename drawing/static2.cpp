//Demonstrate simple pixel drawing
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <cstdlib>
#include <time.h>

class Static_Drawing : public Fl_Widget
{
public:
    Static_Drawing(int x, int y, int w, int h) : Fl_Widget(x,y,w,h) { }

    //virtual override of the draw function
    virtual void draw()
    {
        //loop over each row
        for(int y = this->y(); y<this->y() + h(); y++) {
           //loop over each column
           for(int x = this->x(); x < this->x() + w(); x++) {
                fl_color(rand()%2 ? FL_BLACK : FL_WHITE);
                fl_point(x,y);
           }
        }
    }
};


//update the static frame
void update_frame(void *ptr)
{
    Fl::repeat_timeout(1.0/24.0, update_frame, ptr);

    //redraw our object
    ((Static_Drawing*)ptr)->redraw();
}


int main(int argc, char **argv)
{
    //seed the random number generator
    srand(time(0));

    //create the window and drawing
    Fl_Double_Window *window = new Fl_Double_Window(640, 480, "Line Drawing");
    Static_Drawing *drawing = new Static_Drawing(0, 0, 640, 480);

    //start the timer for the static
    Fl::add_timeout(1.0/24.0, update_frame, drawing);

    //show the window and run the event loop
    window->show(argc, argv);

    return Fl::run();
}
