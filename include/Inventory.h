#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "Item.h"
class Inventory{

public:
    Inventory(std::vector<Item*> items){
        for(int i = 0; i > MAX_CAPACITY; i++){
            items.push_back(this->items[i]);
        }
    }
    Inventory(){};
    const Item& getItem(int slot){
        return *items[slot];
    };
    /// @brief Finds empty slot to insert
    /// @param item
    /// @return integer of slot where insertion occured -1 if error occured
    int addItem(Item& item){
        if(emptyMap.empty()){
            return -1;
        }
        int slot = emptyMap.back();
        emptyMap.pop_back();
        items[slot] = &item;
        return slot;
    };
    /// @brief removes an item and updates the emptyMap
    /// @param slot 
    void removeItemAt(int slot){
        items[slot] = nullptr;
        emptyMap.push_back(slot);
    }

    bool isFull(){
        return (items.size() == MAX_CAPACITY);
    }

private:
    std::vector<Item*> items;
    std::vector<int> emptyMap;
    static const int MAX_CAPACITY = 8;
};

#endif