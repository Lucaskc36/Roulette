#ifndef CUSTOMRANDOM_H
#define CUSTROMRANDOM_H
#include<random>
int customDistribution(std::default_random_engine& engine){
    int randNum = engine() % 100;

    if(randNum < 60){
        //60% chance of generating
        return engine()%6;
    }
}

#endif 