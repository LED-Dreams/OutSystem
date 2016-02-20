#include "Output.hpp"
#include <stdio.h>
#include <bcm2835.h>

#include <iostream>

int main() {
	LEDMatrix matrix(WIDTH, HEIGHT);

	int brightness = 0;

	std::cout << "Brightness: ";
	std::cin >> brightness;
	std::cout << std::endl;

	matrix.DrawStr(0, 0, Color(0, 0, brightness), "Hello");
	matrix.DrawStr(0, 8, Color(brightness, 0, 0), "World");

//	return 0;
	//matrix.Fill(Color(64, 0, 0));
	matrix.Display();

	return 0;

	for(int j = 0; j < HEIGHT; j++) {
		for(int i = 0; i < WIDTH; i++) {
			//bcm2835_st_delay(0, 10000);
			matrix.SetPixel(i, j, Color(brightness, brightness, brightness));
			matrix.Display();
		}
	}
}
