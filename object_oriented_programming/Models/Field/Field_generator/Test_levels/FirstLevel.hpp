#ifndef FIRST_LEVEL_HPP
#define FIRST_LEVEL_HPP

#include "LevelStrategy.hpp"
#include "GenFieldRule.hpp"
#include "GenPlayerRule.hpp"
#include "GenCoordRule.hpp"
#include "GenCountRule.hpp"
#include "GenPassableRule.hpp"
#include "GenWallRule.hpp"
#include "FieldGenerator.hpp"

class FirstLevel: public LevelStrategy{
public:
    Field* generate() final;
};


#endif