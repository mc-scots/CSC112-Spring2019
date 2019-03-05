//Demonstrate complex shapes
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>

class Rotating_Box : public Fl_Widget
{
public:
    Rotating_Box(int x, int y, int w, int h) : Fl_Widget(x,y,w,h) 
    { 
        angle=0;
    }

    virtual void draw()
    {
        //clear out the box
        fl_color(FL_WHITE);
        fl_rectf(x(), y(), w(), h());

        //draw the box
        fl_color(FL_RED);

        //rotate the coordinate system
        fl_push_matrix();
        fl_translate((x()+w())/2, (y()+h())/2);
        fl_rotate(angle);
        fl_translate(-(x()+w())/2, -(y()+h())/2);

        //draw the box as a polygon
        fl_begin_polygon();
        fl_vertex(x()+15, y()+15);
        fl_vertex(x()+w()-15, y()+15);
        fl_vertex(x()+w()-15, y()+h()-15);
        fl_vertex(x()+15, y()+h()-15);
        fl_end_polygon();

        //clear transformations
        fl_pop_matrix();

        //increment our angle
        angle += 15;
    }

private:
    double angle;
};

void update_frame(void *ptr)
{
    //set up the next frame
    Fl::repeat_timeout(1.0/24.0, update_frame, ptr);

    //redraw our box
    ((Rotating_Box*)ptr)->redraw();
}

int main(int argc, char **argv)
{
    Fl_Double_Window *window = new Fl_Double_Window(640, 480, "Rotating Box");
    Rotating_Box *box = new Rotating_Box(100, 100, 540, 380);

    //start the animation
    Fl::add_timeout(1.0/24.0, update_frame, box);

    window->show(argc, argv);
    Fl::run();
}
