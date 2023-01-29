#include "GameLog.hpp"

GameLog::GameLog(Game* game, LoggerPool* pool):game(game), pool(pool){
    game->setObserver(this);
}

Message* GameLog::createMessage(LogType type, std::string msg){
    return new Message(type, msg);
}

void GameLog::update(LogType type, std::string msg){
    pool->addLog(createMessage(type, msg));
}