#include "Headers/Inventory.hpp"

Inventory::Inventory()
{
    items_.reserve(40);
}

void Inventory::addItem(const Item& item)
{      
    items_.push_back(std::make_shared<Item>(item));
}

void Inventory::addItem(const std::shared_ptr<Item> ptr)
{
    items_.push_back(ptr);
}

void Inventory::sortByName()
{
    std::sort(items_.begin(), items_.end(), [](const auto& item1, const auto& item2)
            {
                auto name1 = item1->getName();
                auto name2 = item2->getName();
                return name1 < name2;
            });
}

Items& Inventory::getItems() {return this->items_;}

void Inventory::sortByQuantity()
{
    std::sort(items_.begin(), items_.end(), [](const auto item1, const auto item2)
            {
                auto quantity1 = item1->getQuantity();
                auto quantity2 = item2->getQuantity();
                return quantity1 < quantity2;
            });
}

