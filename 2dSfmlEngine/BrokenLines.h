#pragma once
#include <initializer_list>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include "PrimitiveRenderer.h"

/**
 * \brief ckass alowowing to drawe broken sperate lines using sfml lines render type based on provided points
 */
class BrokenLines: PrimitiveRenderer
{
public:
	/**
	 * \brief construtor for initlizing Broken lines
	 * \param list list of points based on which will drwa lines
	 * \param color color of lines
	 */
	BrokenLines(std::initializer_list<sf::Vector2f> list, sf::Color color);




};

