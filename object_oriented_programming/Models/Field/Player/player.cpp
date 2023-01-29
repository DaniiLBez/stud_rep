#include "player.hpp"
#include <string>
#include "stdlib.h"

Player& Player::operator=(const Player& obj){
        if(this != &obj){
            _hitPoints = obj._hitPoints;
            _points = obj._points;
            _power = obj._power;
        }
        return *this;
    }

int Player::getPower() const{
        return _power;
    }

void Player::setPower(int power){
    _power = power;
    std::string log = "New value of power - " + std::to_string(power);
    //this->notify(LogType::GAME, log);
}

int Player::getHP() const{
    return _hitPoints;
}

void Player::setHP(int hp){
    _hitPoints = hp;
    std::string log = "New value of HP - " + std::to_string(hp);
    //this->notify(LogType::GAME, log);
}

void Player::addPoints(int points){
    _points += points;
    //this->notify();
}

int Player::getPoints() const{
        return _points;
    }