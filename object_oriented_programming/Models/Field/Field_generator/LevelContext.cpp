#include "LevelContext.hpp"

LevelContext::LevelContext(LevelStrategy* strategy):strategy(strategy){}

void LevelContext::setStrategy(LevelStrategy* strategy){
    delete this->strategy;
    this->strategy = strategy;
}

void LevelContext::setlevel(){
    if(strategy){
        field = strategy->generate();
    }
}

Field* LevelContext::getField(){
    return field;
}