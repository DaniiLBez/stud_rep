#ifndef EVENT_INTERFACE_HPP
#define EVENT_INTERFACE_HPP

#include "observable.hpp"
#include "player.hpp"

class Event: public Observable{
public:
    virtual void change_state() = 0;
    virtual Event* clone() = 0;
};


#endif