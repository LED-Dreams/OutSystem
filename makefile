CC=g++
LD=g++

CFLAGS=-std=c++0x -Wall

srcdir=source
VPATH=source
cursordir=../../Input/InputSystem/source

all: Output

Output: Output.o LEDMatrixDraw.o LEDMatrix.o Color.o Cursor.o
	g++ $(CFLAGS) Cursor.o Color.o LEDMatrix.o LEDMatrixDraw.o Output.o -o Output -lbcm2835

Output.o: $(srcdir)/Output.cpp $(srcdir)/Output.hpp
	g++ $(CFLAGS) -c $(srcdir)/Output.cpp

LEDMatrixDraw.o: $(srcdir)/LEDMatrixDraw.cpp $(srcdir)/LEDMatrix.hpp
	g++ $(CFLAGS) -c $(srcdir)/LEDMatrixDraw.cpp

LEDMatrix.o: $(srcdir)/LEDMatrix.cpp $(srcdir)/LEDMatrix.hpp
	g++ $(CFLAGS) -c $(srcdir)/LEDMatrix.cpp

Color.o: $(srcdir)/Color.cpp $(srcdir)/Color.hpp
	g++ $(CFLAGS) -c $(srcdir)/Color.cpp

Cursor.o: $(cursordir)/Cursor.cpp $(cursordir)/Cursor.hpp
	g++ $(CFLAGS) -c $(cursordir)/Cursor.cpp
		
clean:
	rm *.o
