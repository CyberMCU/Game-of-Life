#ifndef GRIDCLASS_HPP
#define GRIDCLASS_HPP

#include "cellClass.hpp"

class Grid{
    public:
    static const int SIZE = 15;
    
    private:
    Cell cells[SIZE][SIZE];

    public:
    Grid(void);
    void clear(void);
    Cell & getCell(int row, int col);
    void display(void) const;
};

#endif