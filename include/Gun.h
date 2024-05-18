#ifndef GUN_H
#define GUN_H
#include <random>
#include <vector>
#include <functional>
#include <iostream>
class Gun{
public:
    Gun(){
        std::vector<int> emptyIndex;
        std::random_device rd; // Obtain a random seed from hardware
        std::default_random_engine engine(rd()); // Seed the random engine

        std::uniform_int_distribution<int> distribution(2,MAX);
        SIZE = distribution(engine);
        std::uniform_int_distribution<int> liveDistribution(ceil(static_cast<double>(SIZE)/3),SIZE/2);
        
        remainingLive = liveDistribution(engine);
        blanks = SIZE - remainingLive;
        std::cout << std::endl;
        std::cout << "Blanks:" << blanks <<std::endl;
        std::cout << "LIVE COUNT: " << remainingLive << std::endl;
        std::cout << "SIZE SET: " << SIZE << std::endl;
        for(int i = 0; i < SIZE; i++){
            emptyIndex.push_back(i);
            ammo.push_back(false);
        }
        while(emptyIndex.size() > SIZE - remainingLive){
            std::uniform_int_distribution<int> dist(0,emptyIndex.size() - 1);
            int rand = dist(engine);
            ammo[emptyIndex[rand]] = true;
            emptyIndex.erase(emptyIndex.begin() + rand);
        }
        std::cout << "AMMO ARRAY: ";
        for(bool i : ammo){
            std::cout << i <<",";
        }
        std::cout << std::endl;
        
    }
    bool peek(int index) const{
        return ammo[index];
    }
    /// @brief shoots player
    /// @param shootFunction 
    /// @return 
    bool shoot(std::function<void()> shootFunction = [](){}){
        if(!ammo.empty()){
        bool result = ammo.back();
        
        if(result){
            remainingLive--;
            shootFunction();
        }
        else{
            blanks--;
        }
        ammo.pop_back();
        remaining = ammo.size();
        return result;
        }
        std::cout << "Out of AMMO" << std::endl;
        return false;
    }
    int getRemaining(){
        return remaining;
    }
    int getRemainingLive(){
        return remainingLive;
    }
    int getBlanks(){
        return blanks;
    }
    bool empty(){
        return ammo.empty();
    }
private:
    const int MAX = 8;
    int remaining;
    int remainingLive;
    int blanks;
    int SIZE;
    std::vector<bool> ammo;

};

#endif