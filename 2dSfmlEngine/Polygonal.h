#pragma once
#include "PrimitiveRenderer.h"

/**
 * \brief Polygonal class allowing to reneder filled polygons using sfml render type
 */
class Polygonal :
    public PrimitiveRenderer
{
public:
	/**
	 * \brief class constrtor that sets up polygon points and its paramters
	 * \param listPoints points of polygon
	 * \param filled is polygon filled
	 * \param color color of polygon
	 */
	Polygonal(std::initializer_list<sf::Vector2f> listPoints, bool filled, sf::Color color = sf::Color::White);


};

