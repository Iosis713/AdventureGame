#include "Headers/Inventory.hpp"

Inventory::Inventory()
{
    items_.reserve(40);
}

void Inventory::addItem(const std::shared_ptr<Item> ptr)
{   
    if(ptr)
    {
        auto it = std::find_if(items_.begin(), items_.end(), [ptr](const auto& item)
            {
                return ptr->getName() == item->getName();
            });
        if(it != items_.end())
        {
            it += ptr->getQuantity();
        }
        else
        {
            items_.push_back(ptr);        
        }
    }
}

void Inventory::removeItem(const std::string& itemName)
{
    auto it = std::find_if(items_.begin(), items_.end(), [itemName](const auto& item)
        {
            return itemName == item->getName();    
        });
    

    if(it != items_.end())
    {
        items_.erase(std::remove(items_.begin(), items_.end(), *it), items_.end());
    }
    else
    {
        throw std::runtime_error("Item not found!");
    }
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
    std::sort(items_.begin(), items_.end(), [](const auto& item1, const auto& item2)
        {
            auto quantity1 = item1->getQuantity();
            auto quantity2 = item2->getQuantity();
            return quantity1 < quantity2;
        });
}

void Inventory::sortByValue()
{
    std::sort(items_.begin(), items_.end(), [](const auto& item1, const auto& item2)
        {
            return item1->getValue() < item2->getValue();
        });
}

