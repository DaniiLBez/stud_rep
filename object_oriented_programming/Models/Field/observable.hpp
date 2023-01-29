#include "Observer.hpp"
#include <string>
#include "message.hpp"

#pragma once

class Observable{
    Observer* obs;
public:
    Observable();
    void setObserver(Observer* obs);
    void notify(LogType, std::string msg);    
};