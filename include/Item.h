#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <unordered_map>
#include <stdexcept>
//Consider using items in a stack
class Item {
public:
    Item(const std::string& id,std::string name): ItemId(id),ItemName(name){};
    std::string getName(){
        return ItemName;
    }
    std::string getId(){
        return ItemId;
    }
    std::string getDescription(){
        return ItemDescription;
    }
    void setQuantity();
    virtual bool onShoot() = 0;

private:
    std::string ItemId;
    std::string ItemName;
    std::string ItemDescription;

};

#endif