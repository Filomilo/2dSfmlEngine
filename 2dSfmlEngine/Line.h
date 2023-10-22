#pragma once
#include <SFML/System/Thread.hpp>

#include "PrimitiveRenderer.h"

/**
 * \brief Line class for drawing line using algorithm specified in document
 */
class Line :
    public PrimitiveRenderer
{
private:
	/**
	 * \brief begging line positon
	 */
	sf::Vector2f begining;
	/**
	 * \brief postion of end of a line
	 */
	sf::Vector2f end;
	/**
	 * \brief amont of point split line into to allow for better optimization
	 */
	int quality = 50;
    

public:
	/**
	 * \brief Line constructor for setting paramters of line obejct =
	 * \param beginingTmp beging postion of line
	 * \param endTmp end positon of line
	 * \param quality amount of points line will be split into for optimization
	 * \param color color of line
	 */
	Line(const sf::Vector2f& beginingTmp, const sf::Vector2f& endTmp, int quality, sf::Color color = sf::Color::White);
    
};

