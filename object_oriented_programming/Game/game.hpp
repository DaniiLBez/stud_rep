#ifndef GAME_HPP
#define GAME_HPP

#include "field.hpp"
#include "field_view.hpp"
#include "command.hpp"
#include "controller.hpp"
#include "mediator.hpp"
#include "player.hpp"
#include "power_buff_event.hpp"
#include "enemy.hpp"
#include "win.hpp"
#include "open_exit.hpp"
#include "observable.hpp"
#include "FieldLog.hpp"
#include "concrete_factory.hpp"
#include <iostream>
#include "FirstLevel.hpp"
#include "TestLevel.hpp"


class Game: public Observable{

public:
    void run();
    bool isNumeric(std::string&);
private:
    FieldView fw;
    FileConfig fc;
    Mediator mediator = Mediator(&fc);
    Field* field;
};

#endif