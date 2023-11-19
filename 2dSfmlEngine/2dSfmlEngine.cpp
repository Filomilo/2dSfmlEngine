/*****************************************************************//**
 * \file   2dSfmlEngine.cpp
 * \brief  main test Function for presenting capabilities of 2d engine
 * 
 * \author 3ID14A
 * \date   October 2023
 *********************************************************************/
#include <SFML/Window.hpp>

#include "BrokenLines.h"
#include "Circle.h"
#include "Elipse.h"
#include "Engine.h"
#include "Line.h"
#include "Point2D.h"
#include "Polygonal.h"

/**
 * \brief main function that tests capabaliteis of 2d egngine, you can choose a number from 2-5 coreesponding to specific instruciton during laboratory
 * \param argc amount of arguments provided
 * \param argv argment provided
 * \return program code
 */
int main(int argc, char* argv []) {
	char choice = 0;
	std::cout << "what would you like to test: " << std::endl;
	std::cout << "2- lines " << std::endl;
	std::cout << "3- cirlce nad flood fill " << std::endl;
	std::cout << "4- transforamtion " << std::endl;
	std::cout << "5- player" << std::endl;
	std::cin >> choice;

	Engine* engine = new Engine(1000, 1000);
	engine->setFramerate(60);
	Circle* circ;
	Polygonal* pol;
	switch (choice)
	{
	case '2':

		engine->addRenderObject(new Line(sf::Vector2f(1, 1), sf::Vector2f(300, 1000), 10, sf::Color::Red));
		engine->addRenderObject(new Line(sf::Vector2f(300, 1000), sf::Vector2f(600, 1), 10, sf::Color::Red));
		engine->addRenderObject(new Line(sf::Vector2f(600, 1), sf::Vector2f(900, 1000), 10, sf::Color::Red));
		engine->addRenderObject(new Line(sf::Vector2f(500, 1), sf::Vector2f(500, 1000), 10, sf::Color::Green));
		engine->addRenderObject(new Line(sf::Vector2f(0, 500), sf::Vector2f(1000, 500), 10, sf::Color::Green));
		engine->addRenderObject(new Point2D(500,500, sf::Color::Yellow));
		engine->addRenderObject((sf::Drawable*)
			new BrokenLines({
				sf::Vector2f(10, 10),
				sf::Vector2f(100, 100),
				sf::Vector2f(500, 50),
				sf::Vector2f(1000, 500)
				},
				sf::Color::Blue));
		break;

	case '3':
		circ = new Circle(500, 500, 50, sf::Color::White); 
		circ->flood_fill(sf::Vector2i(500, 500), sf::Vector2i(300, 300), sf::Vector2i(800, 800), sf::Color::Red);
		engine->addRenderObject(circ);
		engine->addRenderObject(new Elipse(500, 500, 100,200, sf::Color::White));
		engine->addRenderObject(
			new Polygonal({
					sf::Vector2f(231,233),
				sf::Vector2f(123,111),
				sf::Vector2f(12,333),
				sf::Vector2f(556,334),
				sf::Vector2f(888,555),

				}, true));
		break;
	case '4':
		 pol = new Polygonal({
				sf::Vector2f(231,233),
			sf::Vector2f(123,111),
			sf::Vector2f(12,333),
			sf::Vector2f(556,334),
			sf::Vector2f(888,555),

			}, true);
		pol->centerOrigin();
		engine->addRenderObject(pol);
		engine->addUpdatable((Updatable*)pol);

		break;
	case '5':
		engine->setPlayer();
		break;

	default:
		std::cout << "Wrong argument provided";
		return 0;
	}





	engine->start();
	delete engine;
    return 0;
}
