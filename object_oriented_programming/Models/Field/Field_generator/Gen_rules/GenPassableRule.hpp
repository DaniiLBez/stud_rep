#ifndef PASSABLE_RULE_HPP
#define PASSABLE_RULE_HPP

#include "field.hpp"
#include "cell.hpp"

#define VERTICAL 1
#define HORIZONTAL 2

template<int dir, int x, int y, int inc>

class GenPassableRule{

public:
    void operator()(Field* field){
        switch (dir)
        {
        case HORIZONTAL:
            for(int i = 0; i < inc; i++){
                if(field->getField()[y%field->height()][(x+i)%field->width()].getType() == Cell::IMPASSABLE){
                    field->getField()[y%field->height()][(x+i)%field->width()].setDefault();
                }
            }
            break;
        case VERTICAL:
            for(int i = 0; i < inc; i++){
                if(field->getField()[(y+i)%field->height()][x%field->width()].getType() == Cell::IMPASSABLE){
                    field->getField()[(y+i)%field->height()][x%field->width()].setDefault();
                }
            }
            break;
        default:
            break;
        }
    }
};


#endif