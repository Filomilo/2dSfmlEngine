#pragma once
#include "PrimitiveRenderer.h"
class Polygonal :
    public PrimitiveRenderer
{
public:
    Polygonal(std::initializer_list<sf::Vector2f> listPoints, bool filled, sf::Color color=sf::Color::White)
    {

	    for (sf::Vector2f element : listPoints)
	    {
			this->addPixel(element.x, element.y, color);
	    }
		if (!filled) {
			this->addPixel(listPoints.begin()->x, listPoints.begin()->y, color);
			this->set_render_type(sf::LineStrip);
		}
		else
		{
			this->set_render_type(sf::TriangleFan);
		}
	
    }


};

