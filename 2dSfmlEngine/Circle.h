#pragma once
#include "PrimitiveRenderer.h"

/**
 * \brief Cricle class for rendergng circle shape
 */
class Circle :
    public PrimitiveRenderer
{
public:
	/**
	 * \brief Cricle constrtor set points as circle pixel using circle alogritm with 8 symetry lines
	 * \param x x position in 2d space
	 * \param y cirlce y postion in 2d space
	 * \param radius radius of cirlce
	 * \param color color of cirlce
	 */
	Circle(float x, float y, float radius, sf::Color color);

};

