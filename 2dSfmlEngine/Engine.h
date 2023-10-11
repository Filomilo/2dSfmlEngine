#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list>

#include "BrokenLines.h"
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
	void addUpdatable(Polygonal* pol)
	{
		this->updatableObjects.push_back((Updatable*)pol);
	}
};

