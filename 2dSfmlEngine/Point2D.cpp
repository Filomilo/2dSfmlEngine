#include "Point2D.h"



Point2D::Point2D(const sf::Vector2f& position, const sf::Color& color)
{
	set_render_type(sf::Points);
	addPixel(position.x, position.y, color);
}





sf::Vector2f Point2D::get_position() const
{
	return   pixels[0].position;
}


void Point2D::set_position(sf::Vector2f position)
{
	pixels[0].position = position;
}

