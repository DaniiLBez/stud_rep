#include "cell_view.hpp"

void CellView::printCell(Cell& cell){
    switch (cell.getType())
    {
    case Cell::DEFAULT:
        std::cout << "[ ]";
        break;
    case Cell::PUSHED:
        std::cout << "[*]";
        break;
    case Cell::EVENT:
        std::cout << "[?]";
        break;
    case Cell::IMPASSABLE:
        std::cout << "[#]";
        break;
    default:
        break;
    }
}