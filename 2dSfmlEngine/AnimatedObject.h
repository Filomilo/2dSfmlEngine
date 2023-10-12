#pragma once
#include <SFML/System/Time.hpp>

class AnimatedObject
{
public:
	virtual void animate(sf::Time gzmeTime)  = 0;

};

