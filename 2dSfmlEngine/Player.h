#pragma once
#include <stdexcept>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "AnimatedObject.h"
#include "Transformable.h"
#include "Updatable.h"

class Player:
sf::Drawable,
Transformable,
Updatable,
AnimatedObject
{
private:
	sf::Sprite sprite;
	sf::Texture tex;
	sf::Vector2f velocity;
	const float firction = 0.9;
	const int texWidth = 36;
	const int texHeight = 52;
	const int textureLeftBegin = 1;
	const int textureBeginUp = 2;
	const int xOffset = 38;
	const int yOffset = 54;
	const int xCount = 4;
	const int yCount = 4;

	int xCounter = 0;
	int yCounter = 0;

	sf::IntRect texShape;
public:
	Player(float posX, float posy, float width, float heigth, std::string iamgeLocation)
	{
		if (!tex.loadFromFile(iamgeLocation))
		{
			throw std::runtime_error("Couldnt load image");
		}
		texShape = sf::IntRect(
			textureLeftBegin,
			textureBeginUp,
			texWidth,
			texHeight

		);
		sprite = sf::Sprite(tex);
		sprite.scale(2,2);
		yCounter = 3;
		updateTex();
		
		sprite.setPosition(posX, posy);

	}

	void updateTex()
	{
		sprite.setTextureRect(texShape);
		texShape.left = textureLeftBegin + xCounter * (texWidth+4);
		texShape.top = textureBeginUp + yCounter * (texHeight + textureBeginUp);
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

	void animate(sf::Time gzmeTime) override
	{
		float velLimit = 0.09;
		xCounter = ((int)(gzmeTime.asSeconds()*3)) % xCount;

		if(abs(velocity.x)> abs(velocity.y))
		{
			if (abs(velocity.x) < velLimit)
				xCounter = 0;
			if (velocity.x < 0)
				yCounter = 1;
			else
				yCounter = 2;
		}
		else
		{
			if (abs(velocity.y) < velLimit)
				xCounter = 0;
			if (velocity.y < 0)
				yCounter = 3;
			else
				yCounter = 0;
		}
		


		updateTex();
	}
};

