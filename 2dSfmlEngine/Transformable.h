#pragma once
#include <SFML/System/Vector2.hpp>

class Transformable
{
public:
	virtual void move(sf::Vector2f offset);
	virtual void scale(sf::Vector2f offset);
	virtual void rotate(float degreee);
};

