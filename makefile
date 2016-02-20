CC=g++
LD=g++

CFLAGS=-std=c++0x -Wall

srcdir=source
VPATH=source

all: Output

Output: LEDMatrix.o Color.o
	g++ $(CFLAGS) Color.o LEDMatrix.o -o Output -lbcm2835
