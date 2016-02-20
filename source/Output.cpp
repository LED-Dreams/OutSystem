#include "Output.hpp"


int main() {
	LEDMatrix matrix(WIDTH, HEIGHT);

	matrix.DrawRectangle(0, 0, 10, 10, Color(0xFF, 0xFF, 0xFF));

	matrix.Display();
}
