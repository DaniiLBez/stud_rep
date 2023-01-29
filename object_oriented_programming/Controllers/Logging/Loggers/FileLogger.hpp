#ifndef FILE_LOGGER_HPP
#define FILE_LOGGER_HPP

#include "Logger.hpp"
#include <fstream>
#include <string>

class FileLogger: public Logger{
public:
    FileLogger(std::string filename = "Log.txt");
    void print(Message* msg) override;
    ~FileLogger();
private:
    std::ofstream file;
};

#endif