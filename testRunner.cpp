#include <string>
#include <iostream>
#include <memory>
#include <tuple>
#include <gtest/gtest.h>

#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"
#include "Source/Headers/Item.hpp"
#include "Source/Headers/Inventory.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SpriteFixture : public testing::TestWithParam<std::tuple<bool, sf::Vector2f>>
{
public:
    //default size [30, 30]
    std::unique_ptr<Sprite> spritePtr = std::make_unique<Sprite>(sf::Vector2f(200, 200));
};

class ItemFixture : public testing::TestWithParam<std::tuple<unsigned int, unsigned int>>
{
public:
    Item item{sf::Vector2f(50.f, 50.f), 100, 10, "Name", 100};
};

class InventoryFixture : public testing::Test
{
public:
    Inventory inventory;

    void SetUp() override;
};

TEST_F(InventoryFixture, NameSortingTest)
{
    //GIVEN
    SetUp();

    //WHEN
    inventory.sortByName();

    //THEN
    ASSERT_STREQ("Atem", inventory.getItems()[0]->getName().c_str());
}

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

TEST_P(ItemFixture, AddingItemQuantity)
{
    //GIVEN
    std::tuple<unsigned int, unsigned int> tuple = GetParam();

    //WHEN
    item += std::get<1>(tuple);

    //THEN
    ASSERT_EQ(std::get<0>(tuple), item.getQuantity());
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

INSTANTIATE_TEST_CASE_P(AddingItemQuantity, ItemFixture, testing::Values(
    std::make_tuple(10, 0),
    std::make_tuple(17, 7)));


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void InventoryFixture::SetUp()
{
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 10, 2, "ItemA", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 30, 100, "ItemE", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 70, 7, "ItemB", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 23, 8, "Atem", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 190, 92, "Zet", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 120, 15, "Item", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 5, 43, "ItemC", 50));
    inventory.addItem(std::make_shared<Item>(sf::Vector2f(50, 50), 20, 1, "ItemD", 50));
}

