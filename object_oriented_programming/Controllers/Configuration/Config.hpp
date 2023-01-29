#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <map>
#include "player.hpp"
#include "field.hpp"

class Config{

public:
    virtual std::map<char, Player::command> getConfig() = 0;
};


#endif

// #проверка на корректность конфига