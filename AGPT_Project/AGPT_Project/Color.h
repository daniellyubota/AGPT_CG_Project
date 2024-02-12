#pragma once

namespace engine {

class Color
{
public:
	static Color fromRGB(int r, int g, int b);
	static Color fromRGBA(int r, int g, int b, int a);
	static Color fromRGBNormal(float r, float g, float b);
	static Color fromRGBANormal(float r, float g, float b, float a);

	int red() const;
	int green() const;
	int blue() const;
	float redNormal() const;
	float greenNormal() const;
	float blueNormal() const;
	int alpha() const;
	float alphaNormal() const;

private:
	Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {

	}
	float r, g, b, a;
};

const Color RED = Color::fromRGB(255, 0, 0);
const Color GREEN = Color::fromRGB(0, 255, 0);
const Color BLUE = Color::fromRGB(0, 0, 255);

}