CXXFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags`
TARGETS=pong

all: $(TARGETS)
pong: ball.o field.o pong.o
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o $(TARGETS)
