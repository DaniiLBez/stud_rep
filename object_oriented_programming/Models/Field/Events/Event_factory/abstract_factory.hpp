#ifndef ABSTRACT_FACTORY
#define ABSTRACT_FACTORY

#include "event.hpp"
#include "field.hpp"
#include "player.hpp"

class EventAbstractFactory{

public:
    virtual Event* createEvent() = 0;
};

#endif