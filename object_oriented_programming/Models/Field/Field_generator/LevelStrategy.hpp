#ifndef LEVEL_STRATEGY_HPP
#define LEVEL_STRATEGY_HPP


#include "field.hpp"

class LevelStrategy{
public:
    virtual Field* generate() = 0;
    virtual ~LevelStrategy() = default;
};

#endif