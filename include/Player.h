#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Inventory.h"

class Player{
    public:
    Player(std::string name, int Lives):name(name),Lives(Lives){dead = false;};
    Player(std::string name):name(name),Lives(5){dead = false;};
    Player():name("NULL NAME"){Lives = LIVES_MAX;
        dead = false;
    };
    int addLife(int ammount){
        for(int i = 0; i < ammount && i >= LIVES_MAX;i++){
            Lives++;
        }
        return Lives;
    }

    int loseLife(int ammount){
        for(int i = ammount; i > 0 && Lives > 0; i--){
            Lives--;
        }
        if(Lives == 0){
            dead = true;
        }
        return Lives;
    }
    int shootPlayer(Player* Opponent){
        Opponent->loseLife(1);
        return 0;
    }
    int getLives(){
        return Lives;
    }
    std::string getName(){
        return name;
    }
    Inventory* getInventory(){
        return inventory;
    };
    bool isDead(){
        return dead;
    };
    private:

    int Lives;
    bool dead;
    int LIVES_MAX = 5;
    std::string name;
    Inventory* inventory;

};

#endif