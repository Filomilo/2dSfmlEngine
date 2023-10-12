#pragma once
#include "PrimitiveRenderer.h"
class Circle :
    public PrimitiveRenderer
{
public:
    Circle(float x, float y, float radius, sf::Color color)
    {
        this->set_render_type(sf::Points);
        float alphaOffset = 1 / radius;
        for(float alpha=0;alpha<2*3.14;alpha+=alphaOffset)
        {
            this->addPixel(x + radius * cos(alpha), y+radius * sin(alpha), color);
        }
    }

};

