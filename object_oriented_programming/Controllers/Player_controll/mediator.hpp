#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "controller.hpp"
#include "command.hpp"
#include "FileConfig.hpp"

class Mediator{

public:
    Mediator(Config* config):config(config){
        control = new Controller(config);
        control->getControllScheme();
        cr = new CommandReader();
    }

    ~Mediator(){
        delete control;
        delete cr;
    }

    void notifyCommandReader();

    Player::command getControllerCommand();

private:
    ICommand_reader* cr;
    Controller* control;
    Config* config;
};

#endif