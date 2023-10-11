#pragma once
#include <initializer_list>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include "PrimitiveRenderer.h"

class BrokenLines: PrimitiveRenderer
{
public:
	BrokenLines(std::initializer_list<sf::Vector2f> list, sf::Color color)
	{
		for (sf::Vector2f pos: list)
		{
			addPixel(pos.x, pos.y, color);
		}
		set_render_type(sf::Lines);
	}





};

