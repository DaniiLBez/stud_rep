#ifndef WIN_HPP
#define WIN_HPP

#include "Ifield_event.hpp"

class Win:public Ifield_event{
    
public:
    Win(Field* field): field(field){};
    void change_state() override;
    Win* clone() override;
protected:
    Field* field;
};

#endif