#ifndef LEDMATRIX_HPP
#define LEDMATRIX_HPP

#include <vector>
#include <string>
#include <bcm2835.h>
#include <cmath>
#include "Color.hpp"
#include "font5x7.h"

#define SIGN(n)		( ((n) < 0) ? -1 : 1 )

class LEDMatrix
{
public:
	LEDMatrix(int width, int height);
	~LEDMatrix();

	void Clear();

	Color GetPixel(int width, int height) const;
	void SetPixel(int width, int height, const Color &c);

	void Fill(const Color &c);

	void Display() const;

	//Drawing routines
	void DrawLine(int x0, int y0, int x1, int y1, const Color &c);
	void DrawLineHoriz(int x0, int y0, int x1, const Color &c);
	void DrawLineVert(int x0, int y0, int y1, const Color &c);

	void DrawRectangle(int left, int top, int right, int bottom, const Color &c);

	void DrawChar(int x, int y, const Color &c, char ch);
	void DrawStr(int x, int y, const Color &c, const std::string &s);
private:
	int GetPixelID(int width, int height) const;

	int width, height;
	std::vector<Color> colors;
};

#endif
