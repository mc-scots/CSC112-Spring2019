#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

int main(int argc, char **argv)
{
	Fl_Window *window = new Fl_Window(170, 170);
	Fl_Input *numx = new Fl_Input(20,5,140,35, "X:");
	Fl_Input *numy = new Fl_Input(numx->x(), numx->y()+numx->h()+5, 
									numx->w(), numx->h(), "Y: ");
	Fl_Button *add = new Fl_Button(5, numy->y()+numy->h()+5,
	                               35, 35, "+");
	Fl_Button *sub = new Fl_Button(add->x()+add->w()+5, add->y(),
									35, 35, "-");
	Fl_Button *mul = new Fl_Button(sub->x()+sub->w()+5, sub->y(),
									35, 35, "*");
	Fl_Button *div = new Fl_Button(mul->x()+mul->w()+5, mul->y(),
									35, 35, "/");
	Fl_Output *ans = new Fl_Output(40, div->y()+div->h()+5, 
									120, 35, "ANS:");
	
	//Finish the window and display it
	window->end();
	window->show(argc,argv);
	return Fl::run();
}
