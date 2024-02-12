#include "Color.h"

namespace engine {

Color Color::fromRGB(int r, int g, int b)
{
    return fromRGBA(r, g, b, 255);
}

Color Color::fromRGBA(int r, int g, int b, int a)
{
    return { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f };
}

Color Color::fromRGBNormal(float r, float g, float b)
{
    return { r, g, b, 1.0f };
}

Color Color::fromRGBANormal(float r, float g, float b, float a)
{
    return { r, g, b, a };
}

int Color::red() const
{
    return r;
}

int Color::green() const
{
    return g;
}

int Color::blue() const
{
    return b;
}

float Color::redNormal() const
{
    return r / 255.0f;
}

float Color::greenNormal() const
{
    return g / 255.0f;
}

float Color::blueNormal() const
{
    return b / 255.0f;
}

int Color::alpha() const
{
    return a;
}

float Color::alphaNormal() const
{
    return a / 255.0f;
}

}