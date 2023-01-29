#ifndef POWER_BUFF_HPP
#define POWER_BUFF_HPP

#include "Iplayer_event.hpp"

class PowerBuff:public Iplayer_event{
    int mult;
public:
    ~PowerBuff();
    PowerBuff(Player* player, int mult = 100):player(player), mult(mult){};
    void change_state() override;
    PowerBuff* clone() override;
protected:
    Player* player;
};

#endif