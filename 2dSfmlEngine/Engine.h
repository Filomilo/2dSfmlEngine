#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

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
	
		std::cout << sf::Mouse::getPosition().x<<", "<< sf::Mouse::getPosition().y << std::endl;

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

	}

	void render()
	{

		this->window.clear(sf::Color(10,10,10));

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
			eventHandler();
			gameUpdateLogic();
			gameUpdatePhysic();
			render();
			soudUpdate();
			this->timeElapsed = timer.getElapsedTime();
			std::cout << timeElapsed.asMilliseconds() << std::endl;
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

		if (window.isOpen())
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
	

	~Engine();
};

