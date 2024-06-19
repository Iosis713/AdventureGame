#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, int HP, float speed)
    : Sprite(position)
    , HP_(HP)
    , speed_(speed)
{};

void Moveable::updatePosition()
{
    position_.x += velocity_.x;
    position_.y += velocity_.y;
}

int Moveable::getHP() const {return this->HP_;}

void Moveable::setHP(const int HP)
{
    HP_ = HP;
}

void Moveable::setVelocity(const sf::Vector2f velocity)
{
    velocity_ = velocity;
}

