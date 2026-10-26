#include "gameClass.hpp"
#include "gridClass.hpp"
#include <stdio.h>

int GameOfLife::countLivingNeighbors(int row, int col){
    int count = 0;

    int startingRow = 0;
    int startingCol = 0;
    int finalRow = 0;
    int finalCol = 0;

    if(row > 0){
        startingRow = row - 1;
    }
    else{
        startingRow = row;
    }

    if(col > 0){
        startingCol = col - 1;
    }
    else{
        startingCol = col;
    }

    if(col + 1 >= Grid::SIZE){
        finalCol = Grid::SIZE - 1;
    }
    else{
        finalCol = col + 1;
    }

    if(row + 1>= Grid::SIZE){
        finalRow = Grid::SIZE - 1;
    }
    else{
        finalRow = row + 1;
    }

    for(int i = startingRow; i < finalRow + 1; i++){
        for(int j = startingCol; j < finalCol + 1; j++){
            if(grid.getCell(i, j).isAlive() && !(i == row && j == col)){
                count++;
            }
        }
    }

    return count;
}


void GameOfLife::setup(){
    grid.clear();

    // Change initial pattern here
    grid.getCell(4, 3).setAlive(true);
    grid.getCell(4, 4).setAlive(true);
    grid.getCell(4, 5).setAlive(true);
}

void GameOfLife::update(){
    Grid nextGrid;

    for(int row = 0; row < Grid::SIZE; row++){
        for(int col = 0; col < Grid::SIZE; col++){
            if(grid.getCell(row, col).isAlive()){
                if(countLivingNeighbors(row, col) <= 1){
                    nextGrid.getCell(row, col).setAlive(false);
                }
                else if(countLivingNeighbors(row, col) < 4){
                    nextGrid.getCell(row, col).setAlive(true);
                }
                else if(countLivingNeighbors(row, col) > 3){
                    nextGrid.getCell(row, col).setAlive(false);
                }
            }
            else if(countLivingNeighbors(row, col) == 3){
                nextGrid.getCell(row, col).setAlive(true);
            }
        }
    }

    grid = nextGrid;
}

void GameOfLife::display() const{
    grid.display();
}