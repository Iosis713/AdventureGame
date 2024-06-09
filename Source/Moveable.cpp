#include "Headers/Moveable.hpp"

Moveable::Moveable(int HP, sf::Vector2f position, float speed)
    : Sprite(HP, position)
    , speed_(speed)
{};

void Moveable::updatePosition()
{
    position_.x += velocity_.x;
    position_.y += velocity_.y;
}

void Moveable::setVelocity(const sf::Vector2f velocity)
{
    velocity_ = velocity;
}

