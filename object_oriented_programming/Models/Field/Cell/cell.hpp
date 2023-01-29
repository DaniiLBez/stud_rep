#ifndef CELL_HPP
#define CELL_HPP

#include "event.hpp"
#include "player.hpp"

class Cell{

public:
    
    enum cell_type{
        IMPASSABLE,
        PUSHED,
        DEFAULT,
        EVENT
    };

    Cell(cell_type type = DEFAULT):event(nullptr), type(type){}
    Cell& operator=(const Cell& cell);

    void react();

    void setDefault();

    void setImpassable();

    void setEvent(Event* event);

    ~Cell();

    cell_type getType();

private:
    cell_type type;
    Event* event;
};

#endif