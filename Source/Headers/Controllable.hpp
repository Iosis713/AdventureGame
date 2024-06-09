#pragma once
#ifndef CONTROLLABLE
#define CONTROLLABLE

#include "Moveable.hpp"

class Controllable : public Moveable
{
protected:

public:
    Controllable(int HP, sf::Vector2f position, float speed);
    ~Controllable() = default;

    void control();
};

#endif

