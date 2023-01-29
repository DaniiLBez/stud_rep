#ifndef COORD_RULE_HPP
#define COORD_RULE_HPP

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

template <int event, int x_pos, int y_pos>

class GenCoordRule{

public:
    void operator()(Field* field){

        std::map <int, EventAbstractFactory*> factory_map{
            {ENEMY, new EnemyFactory(field->getPlayer(), field)},
            {EXIT, new ExitFactory(field)},
            {BUFF, new PowerBuffFactory(field->getPlayer())}
        };

        try{
            EventAbstractFactory* factory = factory_map.at(event);
            Event* e_event = factory->createEvent();
            field->e_log->subscribe(e_event);
            field->getField()[y_pos][x_pos].setEvent(e_event);
        }catch(...){
            LoggerPool::getInstance()->addLog(new Message(LogType::ERROR, "Couldn't set event"));
        }
    }

};

#endif