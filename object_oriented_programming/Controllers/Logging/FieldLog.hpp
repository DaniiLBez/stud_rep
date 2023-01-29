#ifndef FIELD_LOG_HPP
#define FIELD_LOG_HPP

#include "Observer.hpp"
#include "message.hpp"
#include "field.hpp"
#include "LoggerPool.hpp"

class FieldLog:public Observer{

public:
    Message* createMessage(LogType, std::string msg);
    FieldLog(Field* field, LoggerPool* pool);
    void update(LogType, std::string msg);

private:
    Field* field;
    LoggerPool* pool;
};

#endif