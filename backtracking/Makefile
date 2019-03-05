CXXFLAGS=--std=c++11 -g
CC=g++
TARGETS=sudoku

all: $(TARGETS)
sudoku: main.o sudoku.o backtrack.o
clean:
	rm -f *.o $(TARGETS)
