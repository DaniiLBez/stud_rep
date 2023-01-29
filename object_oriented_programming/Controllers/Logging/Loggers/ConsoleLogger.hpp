#ifndef CONSOLE_LOG_HPP
#define CONSOLE_LOG_HPP

#include "Logger.hpp"
#include "message.hpp"

class ConsoleLogger: public Logger{
public:
    ConsoleLogger() = default;
    void print(Message* msg) override;
};

#endif