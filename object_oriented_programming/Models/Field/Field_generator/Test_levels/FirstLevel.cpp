#include "FirstLevel.hpp"

Field* FirstLevel::generate(){
    FieldGenerator<
        GenFieldRule<10,10>,
        GenPlayerRule<0,0>,
        GenWallRule<20>
    > generator;
    return generator.generate();
}