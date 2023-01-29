#ifndef EXIT_EVENT_HPP
#define EXIT_EVENT_HPP

#include "Ifield_event.hpp"
#include "win.hpp"
#include "message.hpp"
#include <string>

class Exit: public Ifield_event{
    const int points_to_open = 20;
public:
    Exit(Field* field):field(field){};
    void change_state() override;
    Exit* clone() override;
protected:
    Field* field;
};

#endif