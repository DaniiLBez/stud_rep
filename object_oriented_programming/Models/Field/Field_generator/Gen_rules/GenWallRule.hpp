#ifndef WALL_RULE_HPP
#define WALL_RULE_HPP


#include "field.hpp"
#include "LoggerPool.hpp"
#include <random>
#include "cell.hpp"

template <int ... Args>
class GenWallRule{};

template <int x_pos, int y_pos>

class GenWallRule<x_pos,y_pos>{

public:
    void operator()(Field* field){
        try{
            field->getField()[y_pos][x_pos].setImpassable();
        }catch(...){
            LoggerPool::getInstance()->addLog(new Message(LogType::ERROR, "Couldn't set wall"));
        }
    }

};

template<int count>
class GenWallRule<count>{

public:
    void operator()(Field* field){
        int l_count = std::min(count, field->width()*field->height()/3);
        Cell** game_field = field->getField();
        std::mt19937 engine;
        std::random_device device;
        engine.seed(device());
        while(l_count > 0){
            int y_coord = engine()%field->height();
            int x_coord = engine()%field->width();
            if(game_field[y_coord][x_coord].getType() == Cell::DEFAULT){
                game_field[y_coord][x_coord].setImpassable();
                l_count--;
            }
        }
    }
};

#endif