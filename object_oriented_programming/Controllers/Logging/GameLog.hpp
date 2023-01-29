#ifndef GAME_LOG_HPP
#define GAME_LOG_HPP

#include "Observer.hpp"
#include "message.hpp"
#include "game.hpp"
#include "LoggerPool.hpp"

class GameLog:public Observer{

public:
    Message* createMessage(LogType, std::string msg);
    GameLog(Game* game, LoggerPool* pool);
    void update(LogType, std::string msg);

private:
    Game* game;
    LoggerPool* pool;
};

#endif