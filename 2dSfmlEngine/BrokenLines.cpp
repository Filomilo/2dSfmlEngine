#include "BrokenLines.h"


BrokenLines::BrokenLines(std::initializer_list<sf::Vector2f> list, sf::Color color)
{
	for (sf::Vector2f pos : list)
	{
		addPixel(pos.x, pos.y, color);
	}
	set_render_type(sf::Lines);
}


