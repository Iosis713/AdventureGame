#include "Headers/Controllable.hpp"

Controllable::Controllable(int HP, sf::Vector2f position, float speed)
    : Moveable(HP, position, speed)
{};

void Controllable::control()
{
    //side movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity_.x = -speed_;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity_.x = speed_;
    }
    else
    {
        velocity_.x = 0.f;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity_.y = -speed_;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity_.y = speed_;
    }
    else
    {
        velocity_.y = 0.f;
    }

};

