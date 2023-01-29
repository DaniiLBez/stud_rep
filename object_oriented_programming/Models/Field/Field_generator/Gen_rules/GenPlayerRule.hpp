#ifndef PLAYER_RULE_HPP
#define PLAYER_RULE_HPP

#include "player.hpp"
#include "field.hpp"
#include "LoggerPool.hpp"
#include <iostream>

template <int x_pos, int y_pos>

class GenPlayerRule{

public:
    void operator()(Field* field){
        if(field->getPlayer() == nullptr){
            field->setPlayer(new Player());
            field->setPlayerPosition(x_pos, y_pos);
        }else{
            LoggerPool::getInstance()->addLog(new Message(LogType::ERROR, "Player already exists"));
        }
    }

};

#endif