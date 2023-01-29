#ifndef CONCRETE_FACTORY_HPP
#define CONCRETE_FACTORY_HPP

#include "abstract_factory.hpp"
#include "enemy.hpp"
#include "open_exit.hpp"
#include "power_buff_event.hpp"

class EnemyFactory: public EventAbstractFactory{

public:
    EnemyFactory(Player* player, Field* field): field(field), player(player){};

    Event* createEvent(){
        return new Enemy(player, field);
    }

private:
    Field* field;
    Player* player;
};

class ExitFactory: public EventAbstractFactory{

public:
    ExitFactory(Field* field):field(field){};
    
    Event* createEvent(){
        return new Exit(field);
    }

private:
    Field* field;
};

class PowerBuffFactory: public EventAbstractFactory{

public:
    PowerBuffFactory(Player* player):player(player){};
    
    Event* createEvent(){
        return new PowerBuff(player);
    }

private:
    Player* player;
};

#endif