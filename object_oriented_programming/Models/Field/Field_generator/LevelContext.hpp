#ifndef LEVEL_CONTEXT_HPP
#define LEVEL_CONTEXT_HPP

#include "field.hpp"
#include "LevelStrategy.hpp"

class LevelContext{

private:
    Field* field;
    LevelStrategy* strategy;
public:
    explicit LevelContext(LevelStrategy*);
    void setStrategy(LevelStrategy*);
    void setlevel();
    Field* getField();

};


#endif