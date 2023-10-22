#pragma once
#include <SFML/System/Vector2.hpp>

/**
 * \brief Virtual functino providing basic funciton for Transofrming object in a scnene
 */
class Transformable
{
public:
	/**
	 * \brief A function allowing to move object on screen
	 * \param offset Vector of movement that object in move on screen
	 */
	virtual void move(sf::Vector2f offset);
	/**
	 * \brief a function allowing to scale obejct on screen
	 * \param offset Scale vector defining how much object will be scaled in each axis
	 */
	virtual void scale(sf::Vector2f offset);
	/**
	 * \brief a function allowing to rotate obejct in a scnene
	 * \param degreee amount of degrees object will rotate in a scene
	 */
	virtual void rotate(float degreee);
};

