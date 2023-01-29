#ifndef COUNT_RULE_HPP
#define COUNT_RULE_HPP


#include "enemy.hpp"
#include "open_exit.hpp"
#include "power_buff_event.hpp"
#include "field.hpp"
#include "LoggerPool.hpp"
#include "concrete_factory.hpp"
#include <random>
#include "cell.hpp"

#define ENEMY 1
#define EXIT 2
#define BUFF 3

template<int event, int count>

class GenCountRule{

public:
    void operator()(Field* field){

        std::map <int, EventAbstractFactory*> factory_map{
            {ENEMY, new EnemyFactory(field->getPlayer(), field)},
            {EXIT, new ExitFactory(field)},
            {BUFF, new PowerBuffFactory(field->getPlayer())}
        };

        int l_count;
        l_count = std::min(count, field->width()*field->height()/3);
        Cell** game_field = field->getField();
        std::mt19937 engine;
        std::random_device device;
        engine.seed(device());
        EventAbstractFactory* factory = factory_map.at(event);
        while(l_count > 0){
            int y_coord = engine()%field->height();
            int x_coord = engine()%field->width();
            if(game_field[y_coord][x_coord].getType() == Cell::DEFAULT){
                Event* e_event = factory->createEvent();
                field->e_log->subscribe(e_event);
                game_field[y_coord][x_coord].setEvent(e_event);
                l_count--;
            }
        }
    }
};

#endif