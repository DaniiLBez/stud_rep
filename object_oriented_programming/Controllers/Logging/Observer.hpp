#include <string>
#include "message.hpp"
#pragma once

class Observer{
public:
    virtual void update(LogType type, std::string msg) = 0;
};