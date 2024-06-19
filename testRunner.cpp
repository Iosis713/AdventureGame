#include <iostream>
#include <memory>
#include <tuple>
#include <gtest/gtest.h>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SpriteFixture : public testing::TestWithParam<std::tuple<bool, sf::Vector2f>>
{
public:
    //default size [30, 30]
    std::unique_ptr<Sprite> spritePtr = std::make_unique<Sprite>(sf::Vector2f(200, 200));
};

TEST_P(SpriteFixture, collisionTest)
{   
    //GIVEN
    std::tuple<bool, sf::Vector2f> tuple = GetParam();
    std::unique_ptr<Sprite> target = std::make_unique<Sprite>(std::get<1>(tuple));

    //WHEN
    bool result = spritePtr->checkCollision(target);

    //THEN
    ASSERT_EQ(result, std::get<0>(tuple));
}

INSTANTIATE_TEST_CASE_P(CollisionTest, SpriteFixture, testing::Values(
    std::make_tuple(false, sf::Vector2f(170,170)),//vertex
    std::make_tuple(false, sf::Vector2f(230,170)),//vertex
    std::make_tuple(false, sf::Vector2f(170,230)),//vertex
    std::make_tuple(false, sf::Vector2f(230,230)),//vextes
    std::make_tuple(false, sf::Vector2f(180,170)),//edge
    std::make_tuple(false, sf::Vector2f(170,180)),//edge
    std::make_tuple(false, sf::Vector2f(230,180)),//edge
    std::make_tuple(false, sf::Vector2f(180,230)),//edge
    std::make_tuple(true, sf::Vector2f(180,180)),//full
    std::make_tuple(false, sf::Vector2f(240,170)),//none
    std::make_tuple(true, sf::Vector2f(171,171)),//small intersection (1 pixel deep)
    std::make_tuple(true, sf::Vector2f(200,171))//1 pixel deep edge
    ));

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
