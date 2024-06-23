#include "Headers/Item.hpp"

Item::Item(sf::Vector2f position, unsigned int value, unsigned int quantity, std::string name, unsigned int droprate)
    : Sprite(position)
    , value_(value)
    , quantity_(quantity)
    , name_(name)
    , droprate_(droprate)
{
    texture_.loadFromFile("../Source/Images/Sprite.png");
    sprite_.setTexture(texture_);
    sprite_.setPosition(position_);
};

Item& Item::operator++()
{
    quantity_++;
    return *this;
}

Item& Item::operator--()
{
    if(quantity_ >= 1)
    {
        quantity_--;
    }
    return *this;
}

Item& Item::operator+=(unsigned int add)
{
    quantity_ += add;
    return *this;
}

Item& Item::operator-=(unsigned int remove)
{
    if(quantity_ >= remove)
    {
        quantity_ -= remove;
    }
    else
    {
        quantity_ = 0;
    }
    return *this;
}

std::string Item::getName() const {return this->name_;}

unsigned int Item::getQuantity() const {return this->quantity_;}

unsigned int Item::getValue() const {return this->value_;}

