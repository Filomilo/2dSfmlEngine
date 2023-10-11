
#include <SFML/Window.hpp>

#include "BrokenLines.h"
#include "Circle.h"
#include "Elipse.h"
#include "Engine.h"
#include "Line.h"
#include "Point2D.h"
#include "Polygonal.h"

int main() {
   
	Engine* engine = new Engine(1000, 1000);
	engine->setFramerate(60);
	//engine->addRenderObject(new Line(sf::Vector2f(1000,10), sf::Vector2f(200, 200), 10,sf::Color::Red));

	/*
	BrokenLines* brL= new BrokenLines(
		{
		sf::Vector2f(0,0),
			sf::Vector2f(900,100),
			sf::Vector2f(900,1000),
			sf::Vector2f(50,23)
		},
		sf::Color::White);
	engine->addRenderObject((sf::Drawable*)brL);
	*/
	//engine->addRenderObject(new Circle(500, 500, 100, sf::Color::White));
//	engine->addRenderObject(new Elipse(500, 500, 100,200, sf::Color::White));
	/*
	engine->addRenderObject(
		new Polygonal({
				sf::Vector2f(231,233),
			sf::Vector2f(123,111),
			sf::Vector2f(12,333),
			sf::Vector2f(556,334),
			sf::Vector2f(888,555),

	},true)
	
	);
	*/
	Circle* circ = new Circle(500, 500, 10, sf::Color::White);
	
	engine->addRenderObject(circ);
	circ->boundry_fill(sf::Vector2i(500, 500), sf::Vector2i(480, 480), sf::Vector2i(520, 520), sf::Color::Red, sf::Color::Blue);
	engine->start();
	//delete engine;
    return 0;
}
