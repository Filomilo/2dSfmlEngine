#include "PrimitiveRenderer.h"






void PrimitiveRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{

    target.draw(&pixels[0], pixels.size(), renderType);
}




    void PrimitiveRenderer::addPixel(float x, float y, sf::Color color)
    {
        pixels.push_back(sf::Vertex(sf::Vector2f(x, y), color));
    }


    sf::Color PrimitiveRenderer::get_color() const
    {
        return color;
    }


    void PrimitiveRenderer::set_color(sf::Color color)
    {
        this->color = color;
        for (sf::Vertex element : pixels)
        {
            element.color = color;
        }
    }


    sf::PrimitiveType PrimitiveRenderer::get_render_type() const
    {
        return renderType;
    }

   
    void PrimitiveRenderer::set_render_type(sf::PrimitiveType render_type)
    {
        renderType = render_type;
    }

  
    void PrimitiveRenderer::centerOrigin()
    {
        int i = 0;
        sf::Vector2f avg;
        for (sf::Vertex element : pixels)
        {
            i++;
            avg += element.position;

        }
        avg.x /= i;
        avg.y /= i;
        originPoint = avg;
    }


  
    void PrimitiveRenderer::boundry_fill(sf::Vector2i Pos, sf::Vector2i leftCronerBoundery, sf::Vector2i rightCornerBoundery, sf::Color fill_color, sf::Color boundry_color)
    {

        std::cout << "test\n";
        if (this->renderType != sf::Points)
            throw std::runtime_error("Cannot fill non point objects");
        int arraywidth = rightCornerBoundery.x - leftCronerBoundery.x;
        int arrayHeight = rightCornerBoundery.y - leftCronerBoundery.y;
        sf::Vertex* array = new sf::Vertex[arraywidth * arrayHeight];
        //std::fill(array, array + (arraywidth * arrayHeight), sf::Vertex(sf::Vector2f(0, 0)), sf::Color(0, 0, 0, 0));
        for (int i = 0; i < arraywidth * arrayHeight; i++)
        {
            int x = i % arraywidth;
            int y = i / arraywidth;
            array[i] = sf::Vertex(sf::Vector2f(x + leftCronerBoundery.x, y + leftCronerBoundery.y), sf::Color(0, 255, 0, 0));


        }

        for (sf::Vertex element : this->pixels)
        {
            if (
                element.position.x<rightCornerBoundery.x &&
                element.position.x > leftCronerBoundery.x &&
                element.position.y > leftCronerBoundery.y &&
                element.position.y < rightCornerBoundery.y

                )
                array[((int)element.position.x - leftCronerBoundery.x) + ((int)element.position.y - leftCronerBoundery.y) * arraywidth] = element;
        }

        std::stack<sf::Vector2i> pixelsQ;
        pixelsQ.push(Pos);
        int counter = 0;
        while (!pixelsQ.empty())
        {
            sf::Vector2i pos = pixelsQ.top();
            pixelsQ.pop();
            sf::Vector2i arrayPos = sf::Vector2i(pos.x - leftCronerBoundery.x, (pos.y - leftCronerBoundery.y));
            int arrayIndex = arrayPos.x + arrayPos.y * arraywidth;
            sf::Vertex vert = array[arrayIndex];
            array[arrayIndex] = sf::Vertex(vert.position, fill_color);
            counter++;


            ///// rigt X
            if (arrayPos.x < arraywidth)
            {
                if (array[arrayPos.x + 1 + arrayPos.y * arraywidth].color != boundry_color && array[arrayPos.x + 1 + arrayPos.y * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x + 1, pos.y));
                }
            }

            ///// LEft X
            if (arrayPos.x > 0)
            {
                if (array[arrayPos.x - 1 + arrayPos.y * arraywidth].color != boundry_color && array[arrayPos.x - 1 + arrayPos.y * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x - 1, pos.y));
                }
            }

            ///// UP y
            if (arrayPos.y > 0)
            {
                if (array[arrayPos.x + (arrayPos.y - 1) * arraywidth].color != boundry_color && array[arrayPos.x + (arrayPos.y - 1) * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x, pos.y - 1));
                }
            }


            ///// DOWN y
            if (arrayPos.y < arrayHeight)
            {
                if (array[arrayPos.x + (arrayPos.y + 1) * arraywidth].color != boundry_color && array[arrayPos.x + (arrayPos.y + 1) * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x, pos.y + 1));
                }
            }
            std::cout << counter << " / " << pixelsQ.size() << std::endl;
        }

        //array[50+50*arraywidth] = sf::Vertex(sf::Vector2f(50,50), sf::Color::Red);

        this->pixels.clear();

        for (int i = 0; i < arraywidth * arrayHeight; i++)
        {
            //int x = i % arraywidth;
           // int y = i / arraywidth;
         //   sf::Color col = array[i].color;
           // array[i] = sf::Vertex(sf::Vector2f(x + leftCronerBoundery.x, y + leftCronerBoundery.y), col);
            if (array[i].color.a > 0)
                addPixel(i % arraywidth + leftCronerBoundery.x, i / arraywidth + leftCronerBoundery.y, array[i].color);
        }


        delete[] array;




    }


  
    void PrimitiveRenderer::flood_fill(sf::Vector2i Pos, sf::Vector2i leftCronerBoundery, sf::Vector2i rightCornerBoundery, sf::Color fill_color)
    {
        std::cout << "test\n";
        if (this->renderType != sf::Points)
            throw std::runtime_error("Cannot fill non point objects");
        int arraywidth = rightCornerBoundery.x - leftCronerBoundery.x;
        int arrayHeight = rightCornerBoundery.y - leftCronerBoundery.y;
        sf::Vertex* array = new sf::Vertex[arraywidth * arrayHeight];

        //std::fill(array, array + (arraywidth * arrayHeight), sf::Vertex(sf::Vector2f(0, 0)), sf::Color(0, 0, 0, 0));
        for (int i = 0; i < arraywidth * arrayHeight; i++)
        {
            int x = i % arraywidth;
            int y = i / arraywidth;
            array[i] = sf::Vertex(sf::Vector2f(x + leftCronerBoundery.x, y + leftCronerBoundery.y), sf::Color(0, 255, 0, 0));


        }

        for (sf::Vertex element : this->pixels)
        {
            if (
                element.position.x<rightCornerBoundery.x &&
                element.position.x > leftCronerBoundery.x &&
                element.position.y > leftCronerBoundery.y &&
                element.position.y < rightCornerBoundery.y

                )
                array[((int)element.position.x - leftCronerBoundery.x) + ((int)element.position.y - leftCronerBoundery.y) * arraywidth] = element;
        }

        sf::Color colorToFIll = array[(Pos.x - leftCronerBoundery.x) + (Pos.y - leftCronerBoundery.y) * arraywidth].color;
        std::stack<sf::Vector2i> pixelsQ;
        pixelsQ.push(Pos);

        int counter = 0;
        while (!pixelsQ.empty())
        {
            sf::Vector2i pos = pixelsQ.top();
            pixelsQ.pop();
            sf::Vector2i arrayPos = sf::Vector2i(pos.x - leftCronerBoundery.x, (pos.y - leftCronerBoundery.y));
            int arrayIndex = arrayPos.x + arrayPos.y * arraywidth;
            sf::Vertex vert = array[arrayIndex];
            array[arrayIndex] = sf::Vertex(vert.position, fill_color);
            counter++;


            ///// rigt X
            if (arrayPos.x < arraywidth)
            {
                if (array[arrayPos.x + 1 + arrayPos.y * arraywidth].color == colorToFIll && array[arrayPos.x + 1 + arrayPos.y * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x + 1, pos.y));
                }
            }

            ///// LEft X
            if (arrayPos.x > 0)
            {
                if (array[arrayPos.x - 1 + arrayPos.y * arraywidth].color == colorToFIll && array[arrayPos.x - 1 + arrayPos.y * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x - 1, pos.y));
                }
            }

            ///// UP y
            if (arrayPos.y > 0)
            {
                if (array[arrayPos.x + (arrayPos.y - 1) * arraywidth].color == colorToFIll && array[arrayPos.x + (arrayPos.y - 1) * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x, pos.y - 1));
                }
            }


            ///// DOWN y
            if (arrayPos.y < arrayHeight)
            {
                if (array[arrayPos.x + (arrayPos.y + 1) * arraywidth].color == colorToFIll && array[arrayPos.x + (arrayPos.y + 1) * arraywidth].color != fill_color)
                {
                    pixelsQ.push(sf::Vector2i(pos.x, pos.y + 1));
                }
            }
            std::cout << counter << " / " << pixelsQ.size() << std::endl;
        }

        //array[50+50*arraywidth] = sf::Vertex(sf::Vector2f(50,50), sf::Color::Red);

        this->pixels.clear();

        for (int i = 0; i < arraywidth * arrayHeight; i++)
        {
            //int x = i % arraywidth;
           // int y = i / arraywidth;
         //   sf::Color col = array[i].color;
           // array[i] = sf::Vertex(sf::Vector2f(x + leftCronerBoundery.x, y + leftCronerBoundery.y), col);
            if (array[i].color.a > 0)
                addPixel(i % arraywidth + leftCronerBoundery.x, i / arraywidth + leftCronerBoundery.y, array[i].color);
        }


        delete[] array;



    }



    void PrimitiveRenderer::move(sf::Vector2f offset) 
    {
        originPoint += offset;
        for (int i = 0; i < pixels.size(); i++)
        {
            pixels[i] = sf::Vertex(pixels[i].position + offset, pixels[i].color);
        }
    }


    void PrimitiveRenderer::scale(sf::Vector2f offset) 
    {
        sf::Vector2f offsetVector;
        for (int i = 0; i < pixels.size(); i++)
        {
            offsetVector = pixels[i].position - originPoint;
            offsetVector.x *= offset.x;
            offsetVector.y *= offset.y;
            pixels[i] = sf::Vertex(offsetVector + originPoint, pixels[i].color);
        }

    }


    void PrimitiveRenderer::rotate(float degreee) 
    {
        sf::Vector2f offsetVector;
        for (int i = 0; i < pixels.size(); i++)
        {
            offsetVector.x = originPoint.x + (pixels[i].position.x - originPoint.x) * cos(degreee) - (pixels[i].position.y - originPoint.y) * sin(degreee);
            offsetVector.y = originPoint.y + (pixels[i].position.x - originPoint.x) * sin(degreee) + (pixels[i].position.y - originPoint.y) * cos(degreee);

            pixels[i] = sf::Vertex(offsetVector, pixels[i].color);
        }
    }


    void PrimitiveRenderer::update(sf::Time timeElpased) 
    {
        std::cout << originPoint.x << ", " << originPoint.y << std::endl;
        // move(sf::Vector2f(100* timeElpased.asSeconds(), 100* timeElpased.asSeconds()));
        // scale(sf::Vector2f(1.02 , 1.01));
        rotate(0.1 * timeElpased.asSeconds());
    }