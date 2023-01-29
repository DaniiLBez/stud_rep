#ifndef EVENT_LOG_HPP
#define EVENT_LOG_HPP

#include "Observer.hpp"
#include "message.hpp"
#include "event.hpp"
#include "LoggerPool.hpp"

class EventLog:public Observer{

public:
    Message* createMessage(LogType, std::string msg);
    EventLog(LoggerPool* pool):pool(pool){};
    void update(LogType, std::string msg);
    void subscribe(Event*);

private:
    LoggerPool* pool;
};

#endif