#define ENEMY 1
#define EXIT 2
#define BUFF 3
#define VERTICAL 1
#define HORIZONTAL 2

#include "TestLevel.hpp"

Field* TestLevel::generate(){
    FieldGenerator<
        GenFieldRule<10,10>,
        GenPlayerRule<4,4>,
        GenWallRule<30>,
        GenCountRule<ENEMY, 10000>,
        GenCountRule<BUFF, 10>,
        GenCoordRule<EXIT, 3, 3>,
        GenPassableRule<HORIZONTAL,0,0,10>,
        GenPassableRule<VERTICAL,0,0,10>,
        GenPassableRule<HORIZONTAL,0,9,10>,
        GenPassableRule<VERTICAL,9,0,10>
    > generator;
    return generator.generate();
}