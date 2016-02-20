#include "Color.hpp"

Color::Color() {
	r = g = b = 0;
}

Color::Color(int r, int g, int b) {
	this->r = ClampColor(r);
	this->g = ClampColor(g);
	this->b = ClampColor(b);
}

unsigned char Color::GetRed() const {
	return r;
}

unsigned char Color::GetGreen() const {
	return g;
}

unsigned char Color::GetBlue() const {
	return b;
}

void Color::SetRed(int r) {
	this->r = ClampColor(r);
}

void Color::SetGreen(int g) {
	this->g = ClampColor(g);
}

void Color::SetBlue(int b) {
	this->b = ClampColor(b);
}

void Color::Set(int r, int g, int b) {
	this->r = ClampColor(r);
	this->g = ClampColor(g);
	this->b = ClampColor(b);
}

void Color::Set(const Color &c) {
	this->r = c.GetRed();
	this->g = c.GetGreen();
	this->b = c.GetBlue();
}

int Color::ClampColor(int c) const {
	int retval = c;

	if(retval > 255)
		retval = 255;
	else if(retval < 0)
		retval = 0;

	return retval;
}
