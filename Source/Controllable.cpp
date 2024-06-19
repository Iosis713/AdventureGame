#include "Headers/Controllable.hpp"

Controllable::Controllable(sf::Vector2f position, int HP, float speed)
    : Moveable(position, HP, speed)
{};

void Controllable::control()
{
    //reset previous velocity
    velocity_ = {0, 0};
    //side movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity_.x = -speed_;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity_.x = speed_;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity_.y = -speed_;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity_.y = speed_;
    }
};

