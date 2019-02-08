#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <iostream>

using namespace std;

class Click_Me_Button : public Fl_Button
{
public:
	Click_Me_Button(int x, int y, int width, int height, const char *label) :
		Fl_Button(x, y, width, height, label) 
	{ 
		x = 0;
		size = 24;
		
		labelsize(size);
		labelfont(FL_BOLD);
	}
	
	
	virtual int handle(int event)
	{
		//get the default behavior first
		int ret_val = Fl_Button::handle(event);
		
		//then we go our own way!
		if(event == FL_PUSH) {
			x = Fl::event_x();
			return 1;
		} else if(event == FL_LEAVE) {
			label("Click Me");
			return 1;
	    } else if(event == FL_RELEASE) {
			label("Thank You");
			return 1;
		} else if(event == FL_DRAG) {
			int ex = Fl::event_x();
			
			if(ex < x) {
				size--;
			} else if(ex > x) {
				size++;
			}
			x = ex;
			labelsize(size);
			redraw();
			return 1;
		}
		
		
		return ret_val;
	}
	
	private:
	int x;
	int size;
};


int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(340,250);
  Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
  Fl_Button *button = new Click_Me_Button(20, 160, 300, 50, "Click Me");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
