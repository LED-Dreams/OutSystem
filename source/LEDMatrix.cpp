#include "LEDMatrix.hpp"
#include <iostream>
#include <iomanip>

LEDMatrix::LEDMatrix(int width, int height) {
	this->width = width;
	this->height = height;

	//Initialize the color array
	for(int i = 0; i < (width*height); i++) {
		colors.push_back(Color());
	}

	//Initialize the BCM2835 library
	bcm2835_init();
	bcm2835_spi_begin();

	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_32);
}

LEDMatrix::~LEDMatrix() {
	bcm2835_spi_end();
}

Color LEDMatrix::GetPixel(int width, int height) const {
	return colors[GetPixelID(width, height)];
}

void LEDMatrix::SetPixel(int width, int height, const Color &c) {
	colors[GetPixelID(width, height)] = c;
}

void LEDMatrix::Fill(const Color &c) {
	for(auto &color : colors) {
		color.Set(c);
	}
}

void LEDMatrix::Display() const {
	//The APA102 LEDs require 1 additional end frame per 64 LEDs
	int endFrameCount = 1 + colors.size() / 64;

	int byteSize = 4*(1 + colors.size() + endFrameCount);

	char *outBuffer = new char[byteSize];

	//Initialize start frame
	outBuffer[0] = 0;
	outBuffer[1] = 0;
	outBuffer[2] = 0;
	outBuffer[3] = 0;

	//Pack the pixel frames
	for(int i = 0; i < height; i++) {
		int offset = i*width, start, end, inc;

		//If odd-numbered row
		if(i % 2) {
			start = width - 1;
			end = -1;
			inc = -1;
		}
		//If even-numbered row
		else {
			start = 0;
			end = width;
			inc = 1;
		}

		for(int j = start, buffPtr = 4 + 4*offset; j != end; j += inc, buffPtr += 4) {
			outBuffer[buffPtr] = 0xFF;

			outBuffer[buffPtr+1] = colors[offset + j].GetBlue();
			outBuffer[buffPtr+2] = colors[offset + j].GetGreen();
			outBuffer[buffPtr+3] = colors[offset + j].GetRed();
		}
	}

	//Pack the end frames
	for(int i = 0, offset = 4 + 4*width*height; i < endFrameCount; i++, offset += 4) {
		outBuffer[offset] = 0xFF;
		outBuffer[offset+1] = 0x00;
		outBuffer[offset+2] = 0x00;
		outBuffer[offset+3] = 0x00;
	}
/*
	for(int i = 0; i < byteSize; i+= 4) {
		if(!(i % (4*width)))
			std::cout << std::endl;

		std::cout << std::hex << std::setw(2) << (int)((unsigned char)outBuffer[i+4]) << std::hex << std::setw(2) << (int)((unsigned char)outBuffer[i+5]);
		std::cout << std::hex << std::setw(2) << (int)((unsigned char)outBuffer[i+6]) << std::hex << std::setw(2) << (int)((unsigned char)outBuffer[i+7]) << "  ";
	}
*/
	bcm2835_spi_transfern(outBuffer, byteSize);

	delete[] outBuffer;
}

int LEDMatrix::GetPixelID(int width, int height) const {
	return height*this->width + width;
}

