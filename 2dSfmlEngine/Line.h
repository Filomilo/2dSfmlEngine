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
        int interativeIndex;
        int secondIndex;
        
        float beg[2]={ beginingTmp .x< endTmp.x? beginingTmp.x:endTmp.x,beginingTmp .y < endTmp.y ? beginingTmp.y: endTmp.y };
        float end[2] = { beginingTmp.x < endTmp.x ? endTmp.x : beginingTmp.x,beginingTmp.y < endTmp.y ? endTmp.y : beginingTmp.y };


		if(abs(begining.x- endTmp.x)> abs(begining.y - endTmp.y))
		{
            interativeIndex = 0;
            secondIndex = 1;
		}
        else
        {
            interativeIndex =1;
            secondIndex = 0;
        }
        float m = (beg[interativeIndex]- end[interativeIndex]) / (beg[secondIndex] - end[secondIndex]);

        for(beg[interativeIndex]; beg[interativeIndex]< end[interativeIndex];  beg[interativeIndex]= beg[interativeIndex]+quality)
        {
            addPixel(beg[interativeIndex], beg[secondIndex], color);
            beg[secondIndex] +=m;
        }


    }


    
};

