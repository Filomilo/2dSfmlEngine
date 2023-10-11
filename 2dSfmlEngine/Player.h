#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Transformable.h"
#include "Updatable.h"

class Player:
sf::Drawable,
Transformable,
Updatable
{
private:
	sf::RectangleShape sprite;
	sf::Vector2f velocity;
	const float firction = 0.9;

public:
	Player(float posX, float posy, float width, float heigth, sf::Color color)
	{
		sprite = sf::RectangleShape(sf::Vector2f(width, heigth));
		sprite.setFillColor(color);
		sprite.setPosition(posX, posy);
	}

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(sprite);
	}

public:
	void move(sf::Vector2f offset) override
	{
		sprite.move(offset);
	}
	void scale(sf::Vector2f offset) override
{
		sprite.scale(offset);
}
	void rotate(float degreee) override
	{
		sprite.rotate(degreee);
	}
	void update(sf::Time timeElpased) override
	{
		this->move(velocity);
		velocity *= firction;
	}

	void applyVelocity(sf::Vector2f vel)
	{
		velocity += vel;
	}
};

