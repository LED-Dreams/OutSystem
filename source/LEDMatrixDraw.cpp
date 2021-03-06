#include "LEDMatrix.hpp"

void LEDMatrix::DrawLine(int x1, int y1, int x2, int y2, const Color &c) {
	//Check for vertical line
	if(x1 == x2) {
		DrawLineVert(x1, y1, y2, c);
		return;
	}

	//Check for horizontal line
	if(y1 == y2) {
		DrawLineHoriz(x1, y1, x2, c);
		return;
	}

    //Line algorithm from http://www.roguebasin.com/index.php?title=Bresenham%27s_Line_Algorithm
    int delta_x(x2 - x1);
    // if x1 == x2, then it does not matter what we set here
    signed char const ix((delta_x > 0) - (delta_x < 0));
    delta_x = std::abs(delta_x) << 1;

    int delta_y(y2 - y1);
    // if y1 == y2, then it does not matter what we set here
    signed char const iy((delta_y > 0) - (delta_y < 0));
    delta_y = std::abs(delta_y) << 1;

    SetPixel(x1, y1, c);

    if (delta_x >= delta_y)
    {
        // error may go below zero
        int error(delta_y - (delta_x >> 1));

        while (x1 != x2)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                y1 += iy;
            }
            // else do nothing

            error += delta_y;
            x1 += ix;

            SetPixel(x1, y1, c);
        }
    }
    else
    {
        // error may go below zero
        int error(delta_x - (delta_y >> 1));

        while (y1 != y2)
        {
            if ((error >= 0) && (error || (iy > 0)))
            {
                error -= delta_y;
                x1 += ix;
            }
            // else do nothing

            error += delta_x;
            y1 += iy;

            SetPixel(x1, y1, c);
        }
    }
}

void LEDMatrix::DrawLineHoriz(int x0, int y0, int x1, const Color &c) {
	int startX = std::min(x0, x1), endX = std::max(x0, x1);

	for(int x = startX; x <= endX; x++) {
		SetPixel(x, y0, c);
	}
}

void LEDMatrix::DrawLineVert(int x0, int y0, int y1, const Color &c) {
	int startY = std::min(y0, y1), endY = std::max(y0, y1);

	for(int y = startY; y <= endY; y++) {
		SetPixel(x0, y, c);
	}
}

void LEDMatrix::DrawRectangle(int left, int top, int right, int bottom, const Color &c) {
	for(int y = top; y <= bottom; y++) {
		for(int x = left; x <= right; x++)
			SetPixel(x, y, c);
	}
}

void LEDMatrix::DrawChar(int x, int y, const Color &c, char ch) {
	if(ch < 32)
		return;

	int index = 5*(ch - 32);

	for(int i = 0; i < 5; i++) {
		unsigned char line = Font5x7[index + i];

		for(int j = 0; j < 7; j++) {
			if( line & (1 << j) )
				SetPixel(x + i, y + j, c);
		}
	}
}

void LEDMatrix::DrawStr(int x, int y, const Color &c, const std::string &str) {
	for(int i = 0; i < str.length(); i++) {
		DrawChar(x + 6*i, y, c, str.at(i));
	}
}

