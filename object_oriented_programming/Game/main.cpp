#include "LogPoolBuilder.hpp"
#include "game.hpp"
#include "GameLog.hpp"
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

int main(){

    Game game;
    LoggerPool* pool = LoggerPool::getInstance();
    LogPoolBuilder pool_builder = LogPoolBuilder(pool);
    pool_builder.setLogPool();
    GameLog(&game, pool);
    game.run();
    pool->printLogs();
    pool->deleteLoggers();
    return 0;

}