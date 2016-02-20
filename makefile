CC=g++
LD=g++

CFLAGS=-std=c++0x -Wall

srcdir=source
VPATH=source

all: Output

Output: Output.o LEDMatrix.o Color.o
	g++ $(CFLAGS) Color.o LEDMatrix.o LEDMatrixDraw.o Output.o -o Output -lbcm2835

Output.o: $(srcdir)/Output.cpp $(srcdir)/Output.hpp
	g++ $(CFLAGS) -c $(srcdir)/Output.cpp

LEDMatrix.o: $(srcdir)/LEDMatrix.cpp $(srcdir)/LEDMatrixDraw.cpp $(srcdir)/LEDMatrix.hpp
	g++ $(CFLAGS) -c $(srcdir)/LEDMatrix.cpp $(srcdir)/LEDMatrixDraw.cpp

Color.o: $(srcdir)/Color.cpp $(srcdir)/Color.hpp
	g++ $(CFLAGS) -c $(srcdir)/Color.cpp

clean:
	rm *o
