#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list>

#include "BrokenLines.h"
#include "Player.h"
#include "Polygonal.h"

/**
 * \brief Main engine class that hadnle all of rendering udpates and obejcts
 */
class Engine
{
private:
	/**
	 * \brief with of game screen
	 */
	int width;
	/**
	 * \brief height of sreen
	 */
	int height;
	/**
	 * \brief sfml instance of window
	 */
	sf::RenderWindow  window;
	/**
	 * \brief fps of windoow
	 */
	int fps;
	/**
	 * \brief state of game enngine, is it running or should stop
	 */
	bool isRunning=true;
	/**
	 * \brief time since last render
	 */
	sf::Time timeElapsed;
	/**
	 * \brief overall time since game engine started
	 */
	sf::Time timeRunning;
	/**
	 * \brief log file location for errors
	 */
	const std::string logFile = "Engine.log";
	/**
	 * \brief player instnace to be controlered by user
	 */
	Player* player;

	/**
	 * \brief list of drwable objects to ber rendered on a screen
	 */
	std::list<sf::Drawable*> rednerObjects;
	/**
	 * \brief list of updatable objects
	 */
	std::list<Updatable*> updatableObjects;
	/**
	 * \brief list of animatedable obejct
	 */
	std::list<AnimatedObject*> animatedObjects;

	/**
	 * \brief function that handles error and saves it to log fiile
	 * \param description description of error
	 */
	void errorHandler(std::string description);

	/**
	 * \brief function for hanflnig even like pressing keyboard keys or closing window
	 */
	void eventHandler();

	/**
	 * \brief a function to update game logic, here update animiton on animatedable object list
	 */
	void gameUpdateLogic();


	/**
	 * \brief function to update game physic on udpatable object list
	 */
	void gameUpdatePhysic();

	/**
	 * \brief functino to render every objects in renderables obejct list
	 */
	void render();

	/**
	 * \brief a function to update sound of game, here empty prepread for future update of engine
	 */
	void soudUpdate();

	/**
	 * \brief main game loop iterating unttil end of game/system, activating update fucntion and updating time 
	 */
	void gameLoop();

	/**
	 * \brief cleanup funciton to delete pointers applied to game engine
	 */
	void gameCleanUp();

public:
	/**
	 * \brief fucniton to add instance cast to AnimtedObject to system for future animation updates
	 * \param player pointer to Animated object instance
	 */
	void addAnimatable(AnimatedObject* player);

	/**
	 * \brief main constrotr to setup window and libraries for game engine
	 * \param width width of window
	 * \param height height of window
	 * \param isFullScreen whethear or not window is in full scren mode
	 */
	Engine(int width, int height, bool isFullScreen = false);

	/**
	 * \brief function taht actiavtes basic player for game
	 */
	void setPlayer();

	/**
	 * \brief  function that sets max framerate for game
	 * \param fps amount of frames per second
	 */
	void setFramerate(unsigned int fps);

	/**
	 * \brief function that actvates game engine and goes into main loop
	 */
	void start();

	/**
	 * \brief function that allows to drawable pointer to drawable list to be render by game engine in loop
	 * \param object pointer to drawable object to be added
	 */
	void addRenderObject(sf::Drawable* object);

	/**
	 * \brief desctor that activates cleanup for game engine
	 */
	~Engine();

	/**
	 * \brief function that adds updatable objects tp updatables list for future activaitng in game loop
	 * \param pol pointer to Updatablle instnace
	 */
	void addUpdatable(Updatable* pol);
};

