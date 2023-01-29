#include "command.hpp"

void CommandReader::readCommand(){
        char temp_char; 
        std::cin >> temp_char;
        this->command = std::tolower(temp_char);
    }

char CommandReader::getCommand() const{
        return this->command;
    }