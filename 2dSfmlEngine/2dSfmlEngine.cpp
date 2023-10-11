
#include <SFML/Window.hpp>
#include "Engine.h"
int main() {
   
	Engine* engine = new Engine(800, 600);
	engine->setFramerate(60);
	engine->start();
	//delete engine;
    return 0;
}