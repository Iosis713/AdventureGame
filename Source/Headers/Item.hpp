#pragma once
#ifndef ITEM
#define ITEM

#include "Sprite.hpp"

class Item : public Sprite
{
protected:
    const unsigned int value_ = 0;
    unsigned int quantity_ = 1;
    std::string name_ = "Unknown";
    const unsigned int droprate_ = 50; //promiles
                                    
public:
    Item(sf::Vector2f position, unsigned int value, unsigned int quantity, std::string name, unsigned int droprate);
    ~Item() = default;
    
    Item& operator++();
    Item& operator--();
    Item& operator+=(unsigned int add);
    Item& operator-=(unsigned int remove);

    std::string getName() const;
    unsigned int getQuantity() const;
};
#endif

