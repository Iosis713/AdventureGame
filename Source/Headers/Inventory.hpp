#pragma once
#ifndef INVENTORY
#define INVENTORY

#include <iostream>
#include <memory>
#include <vector>

#include "Item.hpp"

//change Sprite to item class
using Items = std::vector<std::shared_ptr<Item>>;

class Inventory
{
protected:
    Items items_;

public:
    Inventory();
    ~Inventory() = default;

    void addItem(const Item& item);
    void addItem(const std::shared_ptr<Item> ptr);

    void sortByName();

    Items& getItems();
};
#endif

