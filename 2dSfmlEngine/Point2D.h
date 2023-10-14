#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "PrimitiveRenderer.h"
class Point2D :
    public PrimitiveRenderer
{

public:
    Point2D(const sf::Vector2f& position, const sf::Color& color=sf::Color::White)
    {
        set_render_type(sf::Points);
        addPixel(position.x, position.y, color);
    }

    Point2D(float x, float y, const sf::Color& color = sf::Color::White): Point2D(sf::Vector2f(x,y), color)
     {
     }


    sf::Vector2f get_position() const
    {
	    return   pixels[0].position;
    }

    void set_position(sf::Vector2f position)
    {
        pixels[0].position = position;
    }



};

