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
    std::sort(items_.begin(), items_.end(), [](auto item1, auto item2)
            {
            auto name1 = item1->getName();
            auto name2 = item2->getName();
            return name1 < name2;
            /*OLD
                //alfabetically
                auto iter1 = name1.begin(); //first letter
                auto iter2 = name2.begin();
                do
                {
                    if(*iter1 < *iter2)
                    {
                        return true;
                    }
                    iter1++;
                    iter2++;
                }while(*iter1 == *iter2);
                //return name1 < name2;
            */
            });
}

Items& Inventory::getItems() {return this->items_;}

