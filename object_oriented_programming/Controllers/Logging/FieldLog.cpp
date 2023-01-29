#include "FieldLog.hpp"

FieldLog::FieldLog(Field* field, LoggerPool* pool):field(field), pool(pool){
    field->setObserver(this);
}

Message* FieldLog::createMessage(LogType type, std::string msg){
    return new Message(type, msg);
}

void FieldLog::update(LogType type, std::string msg){
    pool->addLog(createMessage(type, msg));
}