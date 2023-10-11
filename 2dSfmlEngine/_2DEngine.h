#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>

class _2DEngine
{
private:
	sf::Vector2u screenSize;
	bool shouldWindowClose = false;
	sf::Window window;
	


	void iniit(sf::Vector2u screenSize)
	{
		window.create(sf::VideoMode(screenSize.x, screenSize.y), "_2DEngine");
	}






	void gameLoop()
	{
		while(this->shouldWindowClose)
		{
			
		}
	}

public:
	explicit _2DEngine(int sizeX, int sizeY)
		: screenSize(sf::Vector2u( sizeX,  sizeY))
	{
		iniit(sf::Vector2u(sizeX, sizeY));
	}

	void start()
	{
		
	}


};

