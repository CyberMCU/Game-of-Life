#ifndef GAMECLASS_H
#define GAMECLASS_H

#include "gridClass.hpp"

class GameOfLife{
    private:
    Grid grid;
    int countLivingNeighbors(int row, int col);
    
    public:
    void setup();
    void update();
    void display() const;
};

#endif