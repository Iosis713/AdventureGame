#pragma once
#ifndef CONTROLLABLE
#define CONTROLLABLE

#include <vector>

#include "Moveable.hpp"

class Controllable : public Moveable
{
protected:
    
public:
    Controllable(sf::Vector2f position, int HP, float speed);
    ~Controllable() = default;
    
    void control();
};

#endif

