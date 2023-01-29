#ifndef IPLAYER_EVENT_H
#define IPLAYER_EVENT_H

#include "event.hpp"
#include "player.hpp"

class Iplayer_event: public Event{
    virtual void change_state() = 0;
protected:
    Player* player;
};

#endif