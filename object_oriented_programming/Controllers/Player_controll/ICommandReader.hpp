#ifndef ICOMMAND_READER_HPP
#define ICOMMAND_READER_HPP

class ICommand_reader{

public:
    virtual char getCommand() const = 0;
    virtual void readCommand() = 0;    
};

#endif