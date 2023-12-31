#include "Elipse.h"

Elipse::Elipse(float x, float y, float rx, float ry, sf::Color color)
{
    this->set_render_type(sf::Points);
    float alphaOffset = 1 / (rx > ry ? rx : ry);
    for (float alpha = 0; alpha < 2 * 3.14; alpha += alphaOffset)
    {
        this->addPixel(x + rx * cos(alpha), y + ry * sin(alpha), color);
    }
}