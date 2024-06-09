#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 1080), "Adventure Game");
    
    Controllable controllable(5, sf::Vector2f(500.f, 400.f), 0.2);

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
        controllable.control();
        controllable.updatePosition();
        controllable.draw(window);
        window.display();
    }
    
    using namespace std::chrono_literals;
    {
        std::this_thread::sleep_for(20ms);
    }

    return 0;
}

