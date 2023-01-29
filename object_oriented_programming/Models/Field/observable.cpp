#include "observable.hpp"

Observable::Observable():obs(nullptr){}
void Observable::setObserver(Observer* obs){
    this->obs = obs;
}
void Observable::notify(LogType type, std::string msg){
    obs->update(type, msg);
}