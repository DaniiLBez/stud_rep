#include "EventLog.hpp"


Message* EventLog::createMessage(LogType type, std::string msg){
    return new Message(type, msg);
}

void EventLog::update(LogType type, std::string msg){
    pool->addLog(createMessage(type, msg));
}

void EventLog::subscribe(Event* event){
    event->setObserver(this);
}