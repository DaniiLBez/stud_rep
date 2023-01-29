#include "field_view.hpp"

void FieldView::printField(Field& field){
        for(int i = 0; i < field.height(); i++){
            for(int j = 0; j < field.width(); j++){
                cw.printCell(field.getField()[i][j]);
            }
            std::cout<<'\n';
        }
    }