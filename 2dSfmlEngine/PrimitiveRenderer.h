#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "Transformable.h"
#include "Updatable.h"

/**
 * \brief a base class for rendering any cutom prymitivies and/or pixel(points) shapes
 */
class PrimitiveRenderer :
    public sf::Drawable,
    Transformable,
    Updatable

{
protected:
	/**
	 * \brief type of rendering in sfml allowing better more optimized results
	 */
	sf::PrimitiveType renderType = sf::LineStrip;

	/**
	 * \brief Overided draw fucnction allwoing to show object on screen
	 * \param target place to draw elments on
	 * \param states 
	 */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/**
	 * \brief list of points for pixel rendering or lines dependeing on render type
	 */
	std::vector<sf::Vertex> pixels;
	/**
	 * \brief Color of object
	 */
	sf::Color color;
	/**
	 * \brief origin point around wich object will be rotating
	 */
	sf::Vector2f originPoint;


public:
	/**
	 * \brief function that adds point to pizel vectror for creating objects
	 * \param x position of point on x axisis
	 * \param y position of y on y axis
	 * \param color color of point being added
	 */
    void addPixel(float x, float y, sf::Color color);
	/**
	 * \brief function allowing to get color of an object
	 * \return color of object
	 */
    sf::Color get_color() const;

	/**
	 * \brief funciton to set color of an object
	 * \param color color to set an object to
	 */
    void set_color(sf::Color color);

	/**
	 * \brief function allwoing get type of render that is set on this object
	 * \return render type of an object
	 */
    sf::PrimitiveType get_render_type() const;

	/**
	 * \brief function to set object render type 
	 * \param render_type 
	 */
    void set_render_type(sf::PrimitiveType render_type);

	/**
	 * \brief a function that avrages postion of every point and sets it as origin point of an object
	 */
    void centerOrigin();


	/**
	 * \brief a function that is using boundery fill algorithm to fill object with color
	 * \param Pos postion from which to start fillig obejct
	 * \param leftCronerBoundery left upper corner of boudnery to fill obejct to alow for better optimization
	 * \param rightCornerBoundery right down corner of boundery to fill allowing for better optmizaion
	 * \param fill_color color of object to fill
	 * \param boundry_color color of boundery to stop filling on
	 */
    void boundry_fill(sf::Vector2i Pos, sf::Vector2i leftCronerBoundery, sf::Vector2i rightCornerBoundery, sf::Color fill_color, sf::Color boundry_color);

	/**
	 * \brief a function allowing to fill pixel obejct using flood fill algorithm
	 * \param Pos postion to start filling from
     * \param leftCronerBoundery left upper corner of boudnery to fill obejct to alow for better optimization
     * \param rightCornerBoundery right down corner of boundery to fill allowing for better optmizaion
     * \param fill_color color of object to fill
	 */
	void flood_fill(sf::Vector2i Pos, sf::Vector2i leftCronerBoundery, sf::Vector2i rightCornerBoundery, sf::Color fill_color);
	/**
	 * \brief an overided move function allowing to move obejct and its origin point in a scene
	 * \param offset movement vector that object will move on scene
	 */
	void move(sf::Vector2f offset) override;

	/**
	 * \brief an overided transform function allowing to scale object from origin point
	 * \param offset Vector scale defining scaling values on each axis
	 */
	void scale(sf::Vector2f offset) override;

	/**
	 * \brief an overided transoform fucntion allowign to rote obejct around its origin
	 * \param degreee amount of degres to rotate
	 */
	void rotate(float degreee) override;

	/**
	 * \brief an overided update fucntion here used for presenting transformation capablity
	 * \param timeElpased amount of time passed since prevoius rendering
	 */
	void update(sf::Time timeElpased) override;
};

