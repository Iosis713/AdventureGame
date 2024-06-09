#include "Headers/Controllable.hpp"

Controllable::Controllable(int HP, sf::Vector2f position, float speed)
    : Moveable(HP, position, speed)
{};

void Controllable::control()
{
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
        velocity_.x = 0;
    }
};

