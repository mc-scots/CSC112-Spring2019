CXXFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags`
TARGETS=lines static static2 rotating_box

all: $(TARGETS)
lines:	lines.o
	g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)
static: static.o
	g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)
static2: static2.o
	g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)
rotating_box: rotating_box.o
	g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o $(TARGETS)
