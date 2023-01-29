#ifndef FIELD_GENERATOR_HPP
#define FIELD_GENERATOR_HPP

#define START_POSITION 0,0

#include <vector>
#include "field.hpp"

template <typename ... Args>
class FieldGenerator{

public:
    Field* generate(){
        Field* new_field = new Field();
        (Args()(new_field),...);

        if(new_field->getPlayer() == nullptr){
            new_field->setPlayer(new Player());
            new_field->setPlayerPosition(START_POSITION);
        }
        
        Event* exit = new Exit(new_field);
        new_field->e_log->subscribe(exit);
        new_field->getField()[rand()%new_field->height()][rand()%new_field->width()].setEvent(exit);

        return new_field;
    }
};



#endif