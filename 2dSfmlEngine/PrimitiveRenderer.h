#pragma once
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>


class PrimitiveRenderer :
    public sf::Drawable
{
protected:

    sf::PrimitiveType renderType = sf::LineStrip;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(&pixels[0], pixels.size(), renderType);
    }
    std::vector<sf::Vertex> pixels;
    sf::Color color;
    
public:
    void addPixel(float x, float y, sf::Color color)
    {
        pixels.push_back(sf::Vertex(sf::Vector2f(x, y), color) );
    }

    sf::Color get_color() const
    {
        return color;
    }

    void set_color(sf::Color color)
    {
        this->color = color;
        for (sf::Vertex element : pixels)
        {
            element.color = color;
        }
    }

    sf::PrimitiveType get_render_type() const
    {
	    return renderType;
    }

    void set_render_type(sf::PrimitiveType render_type)
    {
	    renderType = render_type;
    }
    void boundry_fill(sf::Vector2i Pos,sf::Vector2i leftCronerBoundery, sf::Vector2i rightCornerBoundery , sf::Color fill_color, sf::Color boundry_color)
    {
        ///TODO:: implent bounder and flood fill










        if (this->renderType != sf::Points)
            throw std::runtime_error("Cannot fill non point objects");
        int arraywidth = rightCornerBoundery.x - leftCronerBoundery.x;
        int arrayHeight = rightCornerBoundery.y - leftCronerBoundery.y;
        sf::Vertex* array = new sf::Vertex[arraywidth * arrayHeight];
        //std::fill(array, array + (arraywidth * arrayHeight), sf::Vertex(sf::Vector2f(0, 0)), sf::Color(0, 0, 0, 0));
        for(int i=0;i< arraywidth * arrayHeight;i++)
        {
            int x = i % arraywidth;
            int y = i / arraywidth;
            array[i] = sf::Vertex(sf::Vector2f(x + leftCronerBoundery.x, y + leftCronerBoundery.y), sf::Color(0,0,0,0));
        

        }
        
        for (sf::Vertex element : this->pixels)
        {
            if (
                element.position.x<rightCornerBoundery.x  &&
                element.position.x > leftCronerBoundery.x &&
                element.position.y > leftCronerBoundery.y&&
                element.position.y < rightCornerBoundery.y

                )
            array[((int)element.position.x - leftCronerBoundery.x) * ((int)element.position.y - leftCronerBoundery.y)] = element;
        }

        std::stack<sf::Vector2i> pixelsQ;
        pixelsQ.push(Pos);


        while(!pixelsQ.empty())
        {
            sf::Vector2i pos = pixelsQ.top();
            pixelsQ.pop();
            sf::Vertex vert = array[(pos.x-leftCronerBoundery.x) * (pos.y-leftCronerBoundery.y)];
			if(vert.color== boundry_color || vert.color==fill_color)
			{
                break;
			}
            array[(pos.x - leftCronerBoundery.x) * (pos.y - leftCronerBoundery.y)] = sf::Vertex(sf::Vector2f(pos.x, pos.y), fill_color);
            if(pos.x<arraywidth)
            {
                pixelsQ.push(sf::Vector2i(pos.x=1,pos.y));
            }
            if (pos.x >0)
            {
                pixelsQ.push(sf::Vector2i(pos.x - 1, pos.y));
            }
            if (pos.y < arrayHeight)
            {
                pixelsQ.push(sf::Vector2i(pos.x , pos.y+1));
            }
            if (pos.y > 0)
            {
                pixelsQ.push(sf::Vector2i(pos.x , pos.y-1));
            }

        }
        
        for (int i = 0; i < arraywidth * arrayHeight; i++)
        {
            int x = i % arraywidth;
            int y = i / arraywidth;
            sf::Color col = array[i].color;
            array[i] = sf::Vertex(sf::Vector2f(x + leftCronerBoundery.x, y + leftCronerBoundery.y)), sf::Color(0, 0, 0, 0);
           addPixel(array[i].position.x, array[i].position.y, array[i].color);
        }


        delete[] array;


    }

};

