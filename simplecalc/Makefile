CXXFLAGS=-g `fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags`

targets=buttons button calc

all: $(targets)
buttons: buttons.o
	g++ $(CXXFLAGS)  -o $@ $^  $(LDFLAGS)
button: button.o
	g++ $(CXXFLAGS)  -o $@ $^  $(LDFLAGS)
calc: calc.o
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f $(targets) *.o
