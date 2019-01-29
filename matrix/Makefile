CXXFLAGS=-g
TARGETS=matrixTest
CC=g++
LD=g++

all: $(TARGETS)
matrixTest: matrixTest.o matrix.o
matrixTest.o: matrixTest.cpp matrix.h
matrix.o: matrix.cpp matrix.h
clean:
	rm -f $(TARGETS) *.o
