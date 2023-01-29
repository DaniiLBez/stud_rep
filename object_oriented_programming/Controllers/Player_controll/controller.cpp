#include "controller.hpp"
#include <iostream>

void Controller::getCommand(char command){
    if(control_scheme.find(command) != control_scheme.end()){
        this->command = control_scheme.at(command);
    }else{
        this->command = Player::NOTHING;
    }
}

void Controller::getControllScheme(){
    this->control_scheme = this->config->getConfig();
}