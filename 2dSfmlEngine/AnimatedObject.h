#pragma once
#include <SFML/System/Time.hpp>

/**
 * \brief base virtual class providing animete funciton for class
 */
class AnimatedObject
{
public:
	/**
	 * \brief main fucntion that update aniamtebale obejct
	 * \param gzmeTime time since start of engine
	 */
	virtual void animate(sf::Time gzmeTime)  = 0;
	

};

