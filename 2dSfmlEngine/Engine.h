#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list>

#include "BrokenLines.h"
#include "Player.h"
#include "Polygonal.h"

class Engine
{
private:

	int width;
	int height;
	sf::RenderWindow  window;
	int fps;
	bool isRunning=true;
	sf::Time timeElapsed;
	const std::string logFile = "Engine.log";
	Player* player;


	std::list<sf::Drawable*> rednerObjects;
	std::list<Updatable*> updatableObjects;


		void errorHandler(std::string description)
	{
			//TODO: game cleamnup?
			std::ofstream myfile;
			myfile.open(logFile);
			myfile << description;
			myfile.close();

			throw std::runtime_error(description);


	}

	void eventHandler()
	{
	
		//std::cout << sf::Mouse::getPosition().x<<", "<< sf::Mouse::getPosition().y << std::endl;

		sf::Event event;
		while (window.pollEvent(event))
		{
			
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		}
		if (!window.isOpen())
		{
			isRunning = false;
			return;
		}
		sf::Vector2f vel;
		float speedFactor = 100;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			vel+=sf::Vector2f(speedFactor, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			vel += sf::Vector2f(-speedFactor, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			vel += sf::Vector2f(0, speedFactor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			vel += sf::Vector2f(0, -speedFactor);
		}
		player->applyVelocity(vel * timeElapsed.asSeconds());

		}

	
	void gameUpdateLogic()
	{
	}
	void gameUpdatePhysic()
	{
		for (Updatable* element : updatableObjects)
		{
			element->update(this->timeElapsed);
		}
	}

	void render()
	{

		this->window.clear(sf::Color(10,10,10));

		for (sf::Drawable* element : this->rednerObjects)
		{
			this->window.draw(*element);
		}


		window.display();
	}

	void soudUpdate()
	{

	}

	void gameLoop()
	{
		sf::Clock timer;
		while (isRunning)
		{
			timer.restart();
			eventHandler();
			gameUpdateLogic();
			gameUpdatePhysic();
			render();
			soudUpdate();
			this->timeElapsed = timer.getElapsedTime();
		//	std::cout << timeElapsed.asMilliseconds() << std::endl;
		}
	}


	void gameCleanUp()
	{
		//TODO: memory cleaner
	}


public:
	Engine(int width, int height, bool isFullScreen=false)
	{
		this->width = width;
		this->height = height;
		if(isFullScreen)
		window.create(sf::VideoMode(width, height), "Engine", sf::Style::Fullscreen);
		else
			window.create(sf::VideoMode(width, height), "Engine");

		if (!window.isOpen())
			errorHandler("error: creating window");

		player = new Player(width / 2, height / 2, 50, 50, sf::Color::Red);
		addRenderObject((sf::Drawable*)player);
		addUpdatable((Updatable*)player);
		
	}


	void setFramerate(unsigned int fps)
	{
		this->fps = fps;
		this->window.setFramerateLimit(fps);
	}

	void start()
	{
		gameLoop();
		gameCleanUp();
	}


	void addRenderObject(sf::Drawable* object)
	{
		this->rednerObjects.push_back(object);
	}
	

	~Engine();
	void addUpdatable(Updatable* pol)
	{
		this->updatableObjects.push_back((Updatable*)pol);
	}
};

