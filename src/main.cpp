#include <iostream>
#include <string>
#include "../include/Gun.h"
#include "../include/Player.h"
#include "../include/gameManager.h"
#include <iomanip>

int largestName(std::string string1, std::string string2){
    int length = string1.size();
    if(length < string2.size()){
        length = string2.size();
    }
    return length;
}
void clearScreen(){
    std::cout << "\x1B[2J\x1B[H";
}
void printShoot(){
    std::cout << "BANG" <<std::endl;
}
int main(){
    /*
    do{
        std::cout<< "Press any button to continue: Q to quit: ";
        std::cin>> input;
        std::cout<<"\n";
        test.shoot(printShoot);
        std::cout << "Bullets Remaing: " <<test.getRemaining() << std::endl;

    }while(input != "q");
    */

   /****            GunORIENTED GAMES*/
   /* 
    std::string input;
    Gun* game = new Gun();
   bool exit = false;
    std::cout << "Empty?: " << game->empty()  << std::endl;
    while(!game->empty() && !exit){
        std::string input;
        std::cout << "There are " << game->getRemainingLive() << " Live Rounds and " <<game->getBlanks() << " blank rounds" << std::endl;
        while(input != "q" && !game->empty()){
            
            std::cout << "S to shoot opponent, A to shoot Self. Q to Quit" << std::endl;
            std::cin >> input;
            if(input == "s"){
                game->shoot();
            }
            else if(input == "q"){
                exit = true;
            }
        }
        delete game;
        game = new Gun();
    };
    */

    //          USING GAME MANAGER          //
    std::string user1;
    std::string user2;
    std::cout << "Player 1 Enter your name:" << std::endl;
    std::cin >> user1;
    std::cout << "Player 2 Enter your name:" << std::endl;
    std::cin>> user2;
    GameManager game(user1, user2);
    int nameWidth = largestName(user1, user2);

    //GameLoop
    bool exit = false;
    clearScreen();
    while(!exit){
        std::cout <<std::setw(nameWidth) <<game.getPlayer1Name() <<"| Lives:"<< std::setw(5)<< game.player1Health()<< std::endl;
        std::cout <<std::setw(nameWidth) <<game.getPlayer2Name() <<"| Lives:"<< std::setw(5)<< game.player2Health()<< std::endl;
        if(game.isGunEmpty()){
            game.newRound();
        }
        std::cout << std::endl << std::endl;
        std::cout << std::setw(nameWidth + 10) << game.getCurrentPlayerName() << "'s Turn" << std::endl;
        std::cout << "O to shoot Opponent, S to shoot self, q to quit" << std::endl;
        char input;
        std::cin >>input;
        if(input == 'o'){
            game.shootOpponent();
        }
        else if(input == 's'){
            game.shootSelf();
        }
        else if(input == 'q' ){
            exit = true;
        }
        else{
            
        }
        if(game.winner()){
            exit = true;
        };
        clearScreen();
    }
    std::cout << game.winner()->getName() << " is the winner" << std::endl;
    return 1;
}