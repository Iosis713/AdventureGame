#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 1080), "Adventure Game");
    
    Sprite sprite(5, sf::Vector2f(500.f, 400.f));

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        sprite.draw(window);
        window.display();
    }

    return 0;
}

