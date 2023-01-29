#ifndef FIELD_RULE_HPP
#define FIELD_RULE_HPP

#include "field.hpp"
#include "LoggerPool.hpp"
#include "message.hpp"
#include <iostream>

#define MIN_SIZE 10

template <int width, int height>

class GenFieldRule{

public:
    void operator()(Field* field){
        delete field;
        try{
            field = new Field(std::max(height, MIN_SIZE), std::max(width, MIN_SIZE));
            field->setEventLog(new EventLog(LoggerPool::getInstance()));
            std::string log_txt = "Built field with size:" +  std::to_string(field->height()) + 'x' + std::to_string(field->width());
            LoggerPool::getInstance()->addLog(new Message(LogType::INFO, log_txt));
        }catch(...){
            LoggerPool::getInstance()->addLog(new Message(LogType::ERROR, "Couldn't generate field"));
        }
    }
};

#endif