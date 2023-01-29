#ifndef TEST_LEVEL_HPP
#define TEST_LEVEL_HPP

#include "LevelStrategy.hpp"
#include "GenFieldRule.hpp"
#include "GenPlayerRule.hpp"
#include "GenWallRule.hpp"
#include "GenCountRule.hpp"
#include "GenCoordRule.hpp"
#include "GenPassableRule.hpp"
#include "FieldGenerator.hpp"

class TestLevel: public LevelStrategy{
public:
    Field* generate() final;
};


#endif