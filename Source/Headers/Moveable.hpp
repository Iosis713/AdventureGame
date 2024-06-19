#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"

class Moveable : public Sprite
{
protected:
    int HP_ = 5;
    float speed_ = 0.5f;
    sf::Vector2f velocity_ {0.f, 0.f};
    float jumpHeight_ = -20.f;

public:
    Moveable(sf::Vector2f position, int HP, float speed);
    ~Moveable() = default;
    
    void updatePosition();

    int getHP() const;

    void setHP(const int HP);
    void setVelocity(const sf::Vector2f velocity);
};

#endif
