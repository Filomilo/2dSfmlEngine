#include "Player.h"


sf::IntRect texShape;


Player::Player(float posX, float posy, float width, float heigth, std::string iamgeLocation)
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
		sprite.scale(2, 2);
		yCounter = 3;
		updateTex();

		sprite.setPosition(posX, posy);

	}


	void Player::updateTex()
	{
		sprite.setTextureRect(texShape);
		texShape.left = textureLeftBegin + xCounter * (texWidth + 4);
		texShape.top = textureBeginUp + yCounter * (texHeight + textureBeginUp);
	}


	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		target.draw(sprite);
	}


	void Player::move(sf::Vector2f offset) 
	{
		sprite.move(offset);
	}

	void Player::scale(sf::Vector2f offset) 
	{
		sprite.scale(offset);
	}

	void Player::rotate(float degreee) 
	{
		sprite.rotate(degreee);
	}


	void Player::update(sf::Time timeElpased) 
	{
		this->move(velocity);
		velocity *= firction;
	}

	void Player::applyVelocity(sf::Vector2f vel)
	{
		velocity += vel;
	}



	void Player::animate(sf::Time gzmeTime) 
	{
		float velLimit = 0.09;
		xCounter = ((int)(gzmeTime.asSeconds() * 3)) % xCount;

		if (abs(velocity.x) > abs(velocity.y))
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