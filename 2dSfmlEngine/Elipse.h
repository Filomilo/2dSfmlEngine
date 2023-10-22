#pragma once
#include "PrimitiveRenderer.h"

/**
 * \brief Elipse class for renderng elipse
 */
class Elipse :
    public PrimitiveRenderer
{
public:
	/**
	 * \brief Construcot for elipse to set elipse pixels based on privieded paramters
	 * \param x elipse position in x axisis
	 * \param y elpise postion in y axis
	 * \param rx eleipse rasdius in x axis
	 * \param ry eleipse rasdius in y axis
	 * \param color color of elipse
	 */
	Elipse(float x, float y, float rx, float ry, sf::Color color = sf::Color::White);
};

