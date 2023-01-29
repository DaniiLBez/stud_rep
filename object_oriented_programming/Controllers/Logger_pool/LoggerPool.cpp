#include "LoggerPool.hpp"

void LoggerPool::addLog(Message* msg){
    this->logs.push_back(msg);
}

void LoggerPool::printLogs(){
    for(auto elem: this->logs){
        if(isLogging(elem->get_prefix())){
            for(Logger* logger: this->Loggers){
                logger->print(elem);
            }
        }
    }
}

void LoggerPool::addLogger(Logger* logger){
    this->Loggers.push_back(logger);
}

void LoggerPool::deleteLoggers(){
    for(auto logger: this->Loggers){
        delete logger;
    }
}

bool LoggerPool::isLogging(LogType type){
    if(logTypes.find(type) != logTypes.end()){
        return logTypes.at(type);
    }
    return false;
}

void LoggerPool::setLogTypes(std::vector<LogType> types){
    for(auto elem: logTypes){
        logTypes.at(elem.first) = false;
    }

    for(auto elem: types){
        logTypes.at(elem) = true;
    }
}


LoggerPool* LoggerPool::pool = nullptr;

LoggerPool *LoggerPool::getInstance(){
    if(!pool){
        pool = new LoggerPool();
    }
    return pool;
}