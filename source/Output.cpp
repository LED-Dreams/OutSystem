#include "Output.hpp"
#include <stdio.h>
#include <bcm2835.h>

#include <iostream>

int main() {
//	LEDMatrix matrix(WIDTH, HEIGHT);

	std::cout << "initializing cursor" << std::endl;	
		Cursor cursor;

	std::cout << "Checking cursor..." << std::endl;

	while(1) {
		location loc = cursor.receiveCursor();

		std::cout << "Receiving new location : " << loc.toString() << std::endl;
	}

/*	int brightness = 0;

	std::cout << "Brightness: ";
	std::cin >> brightness;
	std::cout << std::endl;

	matrix.DrawStr(0, 0, Color(0, 0, brightness), "Hello");
	matrix.DrawStr(0, 8, Color(brightness, 0, 0), "World");
	matrix.DrawStr(0, 16, Color(0, brightness, 0), "-----");

//	matrix.Fill(Color(0, 16, 0));

	Color c(brightness, 0, brightness);

	matrix.DrawRectangle(12, 8, 20, 16, Color(0, 64, 0));
	matrix.DrawLineHoriz(0, 0, WIDTH-1, c);
	matrix.DrawLineHoriz(0, HEIGHT-1, WIDTH-1, c);
	matrix.DrawLineVert(0, 0, HEIGHT-1, c);
	matrix.DrawLineVert(WIDTH-1, 0, HEIGHT-1, c);

	matrix.DrawLine(0, 0, WIDTH-1, HEIGHT-1, Color(255, 0, 0));
	matrix.DrawLine(WIDTH-1, 0, 0, HEIGHT-1, Color(255, 0, 0));

	matrix.DrawStr(4, 0, Color(32, 32, 0), "Test");

	//matrix.Fill(Color(64, 0, 0));
//	while(1)
		matrix.Display();



	for(int j = 0; j < HEIGHT; j++) {
		for(int i = 0; i < WIDTH; i++) {
			//bcm2835_st_delay(0, 10000);
			matrix.SetPixel(i, j, Color(brightness, brightness, brightness));
			matrix.Display();
		}
	}
	while(1)
		matrix.Display();
*/
}
