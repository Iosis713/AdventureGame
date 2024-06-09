#include "Headers/Sprite.hpp"

Sprite::Sprite(int HP, sf::Vector2f position)
    : HP_(HP)
    , position_(position)
{
    texture_.loadFromFile("../Source/Images/Sprite.png");
    sprite_.setTexture(texture_);
    sprite_.setPosition(position_);
}

void Sprite::draw(sf::RenderWindow& i_window)
{
    sprite_.setPosition(position_);
    i_window.draw(sprite_);
}

int Sprite::getHP() const {return this->HP_;}
sf::Vector2f Sprite::getPosition() const {return this->position_;}

void Sprite::setHP(const int HP) {HP_ = HP;}
void Sprite::setPosition(const sf::Vector2f position) {position_ = position;}

