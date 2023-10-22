#pragma once
#include <SFML/System/Time.hpp>


/**
 * \brief virtual class for defining Objects that are updated during working of engine
 */
class Updatable
{
public:
	/**
	 * \brief A function that updates object during working of engine
	 * \param timeElpased amount of time passed since previous rendering
	 */
	virtual void update(sf::Time timeElpased) = 0;



};

