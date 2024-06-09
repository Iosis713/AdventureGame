#ifndef SPRITE
#define SPRITE

#include <SFML/Graphics.hpp>

#include "Global.hpp"

class Sprite
{
protected:
    int HP_ = 5;
    sf::Vector2f position_ {0.0f, 0.0f};
    const sf::Vector2i size_ {20, 20};
    sf::Texture texture_;
    sf::Sprite sprite_;

public:
    Sprite(int HP, sf::Vector2f position);
    ~Sprite() = default;

    virtual void draw(sf::RenderWindow& i_window);
    
    void setHP(const int HP);
    void setPosition(const sf::Vector2f position);
    
    int getHP() const;
    sf::Vector2f getPosition() const;
};
#endif

