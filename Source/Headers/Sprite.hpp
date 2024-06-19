#ifndef SPRITE
#define SPRITE

#include <memory>

#include <SFML/Graphics.hpp>

#include "Global.hpp"

using ColliderPtr = std::unique_ptr<sf::FloatRect>;

class Sprite
{
protected:
    sf::Vector2f position_{0.0f, 0.0f};
    const sf::Vector2f size_{30.f, 30.f};
    sf::Texture texture_;
    sf::Sprite sprite_;

public:
    Sprite(sf::Vector2f position);
    ~Sprite() = default;
    
    bool checkCollision(const std::unique_ptr<Sprite>& target) const;
    virtual void draw(sf::RenderWindow& i_window);
    
    void setPosition(const sf::Vector2f position);
    
    sf::Vector2f getPosition() const;
    ColliderPtr getCollider() const;

};  
#endif

