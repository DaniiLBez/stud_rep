#include "LogPoolBuilder.hpp"

std::vector<LogType> LogPoolBuilder::getLevels(){
    std::string input_str;
    std::cout << "Choose Levels of logging:\n1.Error logs\n2.Error and Info logs\n3.All logs\n";
    std::cin >> input_str; 
    while ((input_str != "1" && input_str != "2" && input_str != "3"))
    {
        std::cout<<"Wrong number entered. Try again\n";
        std::cin >> input_str;
    }
    return logTypes.at(std::stoi(input_str));
}

std::vector<Logger*> LogPoolBuilder::getLoggers(){
    std::string input;
    std::cout << "Choose out stream:\n1.Console\n2.File\n3.Both\n";
    std::cin >> input;
    while ((input != "1" && input != "2" && input != "3"))
    {
        std::cout<<"Wrong number entered. Try again\n";
        std::cin >> input;
    }
    return loggers.at(std::stoi(input));
}

void LogPoolBuilder::setLogPool(){
    std::cout<<"Do you want to log the game? Press 'y' to log:";
    std::string input;
    std::cin >> input;
    if(input != "y") return;
    pool->setLogTypes(getLevels());
    pool->deleteLoggers();
    std::vector<Logger*> loggers = getLoggers();
    for(auto elem: loggers){
        pool->addLogger(elem);
    }
}
