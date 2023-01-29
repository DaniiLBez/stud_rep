#include "ConsoleLogger.hpp"

void ConsoleLogger::print(Message* msg){
    std::cout << *msg << '\n';
}