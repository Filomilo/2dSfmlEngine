#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "PrimitiveRenderer.h"

/**
 * \brief 2d Point allowing to render one pixel on screen
 */
class Point2D :
    public PrimitiveRenderer
{

public:
	/**
	 * \brief Point 2d constructor that sets paramters of a point
	 * \param position postion of point in 2d scene
	 * \param color color of point
	 */
	Point2D(const sf::Vector2f& position, const sf::Color& color = sf::Color::White);
	/**
	 * \brief a point 2d constuctor allowing to set postion of point by using 2 values instead of one vector
	 * \param x postion of point in x axis
	 * \param y postion of point in y axis
	 * \param color color of point
	 */
	Point2D(float x, float y, const sf::Color& color = sf::Color::White) : Point2D(sf::Vector2f(x, y), color){}

	/**
	 * \brief a function allowing to a get postion of point in 2d space
	 * \return 
	 */
	sf::Vector2f get_position() const;

	/**
	 * \brief a fucntion allowing to set postion of point in 2d space
	 * \param position 
	 */
	void set_position(sf::Vector2f position);



};

