#ifndef IFIELD_EVENT_H
#define IFIELD_EVENT_H

#include "event.hpp"
#include "field.hpp"

class Ifield_event: public Event{
    virtual void change_state() = 0;
protected:
    Field* field;
};

#endif