#ifndef ITEMS_H
#define ITEMS_H
#include "Item.h"

class MagnifyingGlass : Item{
public:
};

class Cig : Item{
    public:


};

class Beer: Item{
    public: 

};
class Handcuffs: Item{
    public:
};
class Saw: Item{
    public:
    //Work through each case of the shoot function. Per shot should apply each multipier:
    ///should also consider if there are multiple items of saw. So multiplier should just be a boolean
    bool onShoot(){
        return true;
    };
};
#endif