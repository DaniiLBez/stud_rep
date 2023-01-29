#include "open_exit.hpp"

Exit* Exit::clone(){
    return new Exit(*this);
}

void Exit::change_state(){

    this->notify(LogType::GAME, "Event activated. Exit is open");
    Event* exit = new Win(field);
    field->e_log->subscribe(exit);
    field->getField()[field->width()-1][field->height()-1].setEvent(exit);
    return;
    
}