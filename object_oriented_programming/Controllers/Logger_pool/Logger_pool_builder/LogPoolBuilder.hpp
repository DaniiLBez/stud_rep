#ifndef LOGPOOL_BUILDER_HPP
#define LOGPOOL_BUILDER_HPP

#include "LoggerPool.hpp"
#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"
#include "message.hpp"
#include <iostream>
#include <vector>
#include <map>

class LogPoolBuilder{

public:
    LogPoolBuilder(LoggerPool* pool):pool(pool){};
    std::vector<Logger*> getLoggers();
    std::vector<LogType> getLevels();
    void setLogPool();
private:
    
    std::map<int, std::vector<LogType>> logTypes{
        {1, std::vector<LogType>{LogType::ERROR}},
        {2, std::vector<LogType>{LogType::ERROR, LogType::INFO}}, 
        {3, std::vector<LogType>{LogType::ERROR, LogType::INFO, LogType::GAME}}
    };

    std::map<int, std::vector<Logger*>> loggers{
        {1, std::vector<Logger*>{new ConsoleLogger()}},
        {2, std::vector<Logger*>{new FileLogger()}}, 
        {3, std::vector<Logger*>{new ConsoleLogger(), new FileLogger()}}
    };
protected:
    LoggerPool* pool;
};


#endif