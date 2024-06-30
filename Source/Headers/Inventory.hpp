#pragma once
#ifndef INVENTORY
#define INVENTORY

//#include <stdexcept>
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

    void addItem(const std::shared_ptr<Item> ptr);
    void removeItem(const std::string& itemName);
    void sortByName();
    void sortByQuantity();
    void sortByValue();
    
    Items& getItems();
};
#endif

