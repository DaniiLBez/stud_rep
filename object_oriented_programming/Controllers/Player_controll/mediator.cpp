#include "mediator.hpp"

void Mediator::notifyCommandReader(){
        cr->readCommand();
        control->getCommand(cr->getCommand());
    }
    
Player::command Mediator::getControllerCommand(){
    return control->command;
}