#include "Headers/Sprite.hpp"

Sprite::Sprite(sf::Vector2f position)
    : position_(position)
{
    texture_.loadFromFile("../Source/Images/Sprite.png");
    sprite_.setTexture(texture_);
    sprite_.setPosition(position_);
}

bool Sprite::checkCollision(const std::unique_ptr<Sprite>& target) const
{   
    //only left and top edges are contained
    //therefore vertexes and edges collision is not captured
    if(getCollider()->intersects(*target->getCollider()))
    {
        return true;
    }
    return false;
}

void Sprite::draw(sf::RenderWindow& i_window)
{
    sprite_.setPosition(position_);
    i_window.draw(sprite_);
}

sf::Vector2f Sprite::getPosition() const {return this->position_;}
ColliderPtr Sprite::getCollider() const
{
    ColliderPtr collider = std::make_unique<sf::FloatRect>(position_, size_);
    return collider;
}

void Sprite::setPosition(const sf::Vector2f position) {position_ = position;}

