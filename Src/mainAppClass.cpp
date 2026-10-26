#include "mainAppClass.hpp"
#include "gameClass.hpp"
#include <stdio.h>

void MainApp::run(int numberOfStep){
    GameOfLife game;
    game.setup();

    printf("\n\n\r --- Generation 0 ---  \n\r");
    game.display();

    for(int step = 1; step <= numberOfStep; step++){
        game.update();
        printf("\n\n\r --- Generation %d --- \n\r", step);
        game.display();
        getchar();
    }
}