#include "Sprite.hpp"

class Moveable : public Sprite
{
protected:
    float speed_ = 3.f;
    sf::Vector2f velocity_ {0.f, 0.f};
    float jumpHeight_ = -20.f;

public:
    Moveable(int HP, sf::Vector2f position, float speed);
    ~Moveable() = default;
    
    void updatePosition();

    void setVelocity(const sf::Vector2f velocity);
};

