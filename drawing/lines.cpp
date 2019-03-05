//Demonstrate simple line drawing
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <cstdlib>
#include <time.h>

class Line_Drawing : public Fl_Widget
{
public:
    Line_Drawing(int x, int y, int w, int h) : Fl_Widget(x,y,w,h) { }

    //virtual override of the draw function
    virtual void draw()
    {
        //set the color to black
        fl_color(FL_BLACK);

        //draw a line along the diagonal of this widget
        fl_line(x(), y(), x() + w(), y() + h());

        //select a random color
        fl_color(rand() & 0xffffff00 | 0x0e000000);

        //draw a random line
        fl_line(x() + rand()%w(), y() + rand()%h(),
                x() + rand()%w(), y() + rand()%h());
    }

    //virtual override of the handle function (event handler)
    virtual int handle(int event)
    {
        redraw();  //redraw my widget
        return 1;
    }
};


int main(int argc, char **argv)
{
    //seed the random number generator
    srand(time(0));

    //create the window and drawing
    Fl_Double_Window *window = new Fl_Double_Window(640, 480, "Line Drawing");
    Line_Drawing *drawing = new Line_Drawing(0, 0, 640, 480);

    //show the window and run the event loop
    window->show(argc, argv);

    return Fl::run();
}
