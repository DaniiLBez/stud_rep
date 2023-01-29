#include "enemy.hpp"

void Enemy::change_state(){
    
    this->notify(LogType::GAME, "Event activated. Player attack the enemy.");

    if(player->getPower() > this->_hp + this->_power){
        player->addPoints(points_for_kill);
        this->notify(LogType::GAME, "Enemy defeated. Player earn points.");
        return;
    }

    player->setHP(player->getHP()+player->getPower()-this->_power);
        
    if(player->getHP() <= 0){
        field->changeState(Field::LOSE);
        return;
    }

}

Enemy* Enemy::clone(){
    return new Enemy(*this);
}
