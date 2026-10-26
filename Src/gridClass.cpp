#include "gridClass.hpp"
#include <stdio.h>

Grid::Grid(void){
    clear();
}

void Grid::clear(void){
    for(int i  = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cells[i][j].setAlive(false);
        }
    }
}

Cell& Grid::getCell(int row, int col){
    if(row < 0 && row > SIZE){
        printf("ERROR IN SIZE -> ROW");
        while(1);
    }
    else if(col < 0 && col > SIZE){
        printf("ERROR IN SIZE -> COL");
        while(1);
    }
    else{
        return cells[row][col];
    }
}

void Grid::display(void) const{
    for(int i  = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(cells[i][j].isAlive() == true){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n\r");
    }
}