#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <cctype>
#include "ICommandReader.hpp"

class CommandReader: public ICommand_reader{
private:
    char command;
public:
    void readCommand();
    char getCommand() const;
};

#endif