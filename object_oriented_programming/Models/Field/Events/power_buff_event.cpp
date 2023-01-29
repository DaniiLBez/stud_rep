#include "power_buff_event.hpp"

void PowerBuff::change_state(){
    this->notify(LogType::GAME, "Event activated. Player get buff");
    player->setPower(player->getPower()+mult);
}

PowerBuff* PowerBuff::clone(){
    return new PowerBuff(*this);
}

PowerBuff::~PowerBuff(){
    mult = 0;
}