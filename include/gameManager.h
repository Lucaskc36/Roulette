#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Player.h"
#include "Gun.h"
#include <string>
#include <iostream>
class GameManager{
    public:
    GameManager(const std::string& player1Name, const std::string& player2Name){
        Player1 = new Player(player1Name);
        Player2 = new Player(player2Name);
        curPlayer = Player1;
        opponent = Player2;
        gun = new Gun();
    }
    //Need to think about items in this process
    //could consider a queue for commands such as Use items: skip turn, possible through handcuff object,
    //and shoot self mechanic, all would be doing is bypassing the swapPlayer.
    bool shootOpponent(){
        bool result = gun->shoot();
        if(result) {opponent->loseLife(1);}
        swapPlayer();
        return result;
    }
    bool shootSelf(){
        bool result = gun->shoot();
        if(result) {
            curPlayer->loseLife(1);
            swapPlayer();
        };
        return result;

    }
    Gun* getRound(){
        return gun;
    }
    int getRemaining(){
        return gun->getRemaining();
    }
    bool isGunEmpty(){
        return gun->empty();
    }
    int player1Health(){
        return Player1->getLives();
    }
    int player2Health(){
        return Player2->getLives();
    }
    std::string getCurrentPlayerName(){
        return curPlayer->getName();
    }
    Player* winner(){
        if(Player1->isDead()){
            return Player2;
        }
        else if(Player2->isDead()){
            return Player1;
        }

        return nullptr;
    }
    bool gameOver(){
        return 0;
    }
    void newRound(){
        delete gun;
        gun = new Gun();
    };
    std::string getPlayer1Name(){
        return Player1->getName();
    }
    std::string getPlayer2Name(){
        return Player2->getName();
    }
    private:
    Player* Player1;
    Player* Player2;
    Player* curPlayer;
    Player* opponent;
    Gun* gun;

    void swapPlayer(){
        Player* hold = curPlayer;
        curPlayer = opponent;
        opponent = hold;
    }
};


#endif