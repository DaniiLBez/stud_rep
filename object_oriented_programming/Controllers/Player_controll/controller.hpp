#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.hpp"
#include "Config.hpp"
#include <map>
#include <iostream>

class Controller{
private:
    
    Config* config;
public:
    Controller(Config* config):config(config){};

    void getCommand(char command);

    void getControllScheme();
    std::map<char, Player::command> control_scheme;
    Player::command command;
};

#endif