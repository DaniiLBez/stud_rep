#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <map>

enum LogType{
    GAME,
    INFO,
    ERROR
};

class Message{
    
public:
    LogType get_prefix();
    std::string get_time_message();
    std::string get_message();
    Message(LogType, std::string msg);
    friend std::ostream& operator<<(std::ostream&, Message&);

private:
    std::string message;
    LogType type;
    std::string message_time;
    std::map<LogType, std::string> prefixs {
            {LogType::GAME, "[GAME]"},
            {LogType::INFO, "[INFO]"},
            {LogType::ERROR, "[ERROR]"}
    };
};


#endif