#pragma once
#include <SFML/System/Thread.hpp>

#include "PrimitiveRenderer.h"
class Line :
    public PrimitiveRenderer
{
private:

    sf::Vector2f begining;
    sf::Vector2f end;

    int quality = 50;
    

public:
    Line(const sf::Vector2f& beginingTmp, const sf::Vector2f& endTmp, int quality, sf::Color color=sf::Color::White)
	    : begining(beginingTmp),
	      end(endTmp),
        quality(quality)
			
    {
       set_render_type(sf::Points);

        
        bool isHorizontal=abs(beginingTmp.x- endTmp.x)> abs(beginingTmp.y - endTmp.y);
       // std::cout << "test\n";


        char firstIndex=0;
    	char secondIndex=0;
        float firstPoint[2];
        float secondPoint[2];

        if(isHorizontal)
        {
            firstIndex = 0;
            secondIndex = 1;
            if(beginingTmp.x< endTmp.x)
            {
                firstPoint[0] = beginingTmp.x;
                firstPoint[1] = beginingTmp.y;
                secondPoint[0] = endTmp.x;
                secondPoint[1] = endTmp.y;
            }
            else
            {
                secondPoint[0] = beginingTmp.x;
                secondPoint[1] = beginingTmp.y;
                firstPoint[0] = endTmp.x;
                firstPoint[1] = endTmp.y;
            }
        }
        else
        {
            firstIndex = 1;
            secondIndex = 0;
            if (beginingTmp.y <  endTmp.y)
            {
                firstPoint[0] = beginingTmp.x;
                firstPoint[1] = beginingTmp.y;
                secondPoint[0] = endTmp.x;
                secondPoint[1] = endTmp.y;
            }
            else
            {
                secondPoint[0] = beginingTmp.x;
                secondPoint[1] = beginingTmp.y;
                firstPoint[0] = endTmp.x;
                firstPoint[1] = endTmp.y;
            }
        }
        

        
		
        float m = (firstPoint[secondIndex] - secondPoint[secondIndex]) /  (firstPoint[firstIndex] - secondPoint[firstIndex]);
        m = (firstPoint[firstIndex] - secondPoint[firstIndex]) == 0 ? 0 : m;
        for(firstPoint[firstIndex]; firstPoint[firstIndex]< secondPoint[firstIndex];  firstPoint[firstIndex]= firstPoint[firstIndex]+1)
        {
            addPixel(firstPoint[0], firstPoint[1], color);
            firstPoint[secondIndex] +=m;
        }
        

    }


    
};

