#include "win.hpp"

void Win::change_state(){
    this->notify(LogType::GAME, "Event activated.");
    field->changeState(Field::WIN);
}

Win* Win::clone(){
    return new Win(*this);
}