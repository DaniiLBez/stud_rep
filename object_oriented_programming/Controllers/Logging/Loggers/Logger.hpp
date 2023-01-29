#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "message.hpp"
#include <iostream>

class Logger{
public:
    virtual void print(Message* msg) = 0;
    virtual ~Logger() = default;
};

#endif