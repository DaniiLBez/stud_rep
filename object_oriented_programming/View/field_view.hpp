#ifndef FIELDVIEW_HPP
#define FIELDVIEW_HPP

#include "cell_view.hpp"
#include "field.hpp"
#include <iostream>

class FieldView{
private:
    CellView cw;
public:
    void printField(Field& field);
};

#endif