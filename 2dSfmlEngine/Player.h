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

/**
 * \brief a class allowing to add player to game engine
 */
class Player:
sf::Drawable,
Transformable,
Updatable,
AnimatedObject
{
private:
	/**
	 * \brief sfml sprite obejet for defining render object
	 */
	sf::Sprite sprite;
	/**
	 * \brief sfml texture object for defing character sprite texture
	 */
	sf::Texture tex;
	/**
	 * \brief velocity of a player defing how much it shuld move in each second
	 */
	sf::Vector2f velocity;
	/**
	 * \brief friciton defining how much player movement will slow down
	 */
	const float firction = 0.9;
	/**
	 * \brief width of one sprite texture
	 */
	const int texWidth = 36;
	/**
	 * \brief height of one sprite texure
	 */
	const int texHeight = 52;
	/**
	 * \brief initila texture postion in x axis
	 */
	const int textureLeftBegin = 1;
	/**
	 * \brief inital texutre postion in y axis
	 */
	const int textureBeginUp = 2;
	/**
	 * \brief texute offset betwern sprite on a sprite grid in x axis
	 */
	const int xOffset = 38;
	/**
	 * \brief texture offset betwwen sprites on a sprite grid in y axis
	 */
	const int yOffset = 54;
	/**
	 * \brief amount of sprites in x axis
	 */
	const int xCount = 4;
	/**
	 * \brief amount of sprites in y axis
	 */
	const int yCount = 4;
	/**
	 * \brief variable defing what spire on what x axis texture sprite grid is active
	 */
	int xCounter = 0;
	/**
	 * \brief a variable defining what spirte on y axis is active on a sprite gird
	 */
	int yCounter = 0;
	/**
	 * \brief active cutotut from texture 
	 */
	sf::IntRect texShape;
public:
	/**
	 * \brief constructir for setting up paraameters of player
	 * \param posX position of player in x axis
	 * \param posy postion on player in y axis
	 * \param width width of player sprite
	 * \param heigth height of player sprite
	 * \param iamgeLocation location of iamge fortexture
	 */
	Player(float posX, float posy, float width, float heigth, std::string iamgeLocation);

	/**
	 * \brief functuib that update texture sprite based on a seleciton
	 */
	void updateTex();


protected:
	/**
	 * \brief sfnk draw fucntion overirde rendering for player sprite
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
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
	 * \brief fucntion that updates playeer positoin based on its velocity
	 * \param timeElpased time since last render
	 */
	void update(sf::Time timeElpased) override;

	/**
	 * \brief fucntion that appllies velocity to object
	 * \param vel velocity vector
	 */
	void applyVelocity(sf::Vector2f vel);


	/**
	 * \brief a function that updates sprite seleciton absed on player velocity direction and time since startof engine
	 * \param gzmeTime time since engine start
	 */
	void animate(sf::Time gzmeTime) override;
};

