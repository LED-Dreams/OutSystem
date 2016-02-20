#ifndef COLOR_HPP
#define COLOR_HPP



class Color
{
public:
	Color();
	Color(int r, int g, int b);

	unsigned char GetRed() const;
	unsigned char GetGreen() const;
	unsigned char GetBlue() const;

	void SetRed(int r);
	void SetGreen(int g);
	void SetBlue(int b);

	void Set(int r, int g, int b);
	void Set(const Color &c);
private:
	int ClampColor(int c) const;

	unsigned char r, g, b;
};

#endif
