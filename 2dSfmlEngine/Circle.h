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
		float newX,newY;
        for(float alpha=0;alpha<2*3.14/8;alpha+=alphaOffset)
        {
			newX =  radius * cos(alpha);
			newY =  radius * sin(alpha);
            this->addPixel(x+newX, y+newY, color);
			this->addPixel(x-newX, y+newY, color);
			this->addPixel(x-newX, y-newY, color);
			this->addPixel(x+newX, y-newY, color);

			this->addPixel(x + newY, y + newX, color);
			this->addPixel(x  -newY, y + newX, color);
			this->addPixel(x  -newY, y - newX, color);
			this->addPixel(x + newY, y - newX, color);
		
        }
    }

};

