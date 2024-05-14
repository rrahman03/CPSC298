#include "TicTacToe.h"
#include <iostream>

int main() {
    std::cout << "Tic Tac Toe\n";
    std::cout << "The top row is row number 0, the middle row number 1, and the bottom row is row number 2.\n";
    std::cout << "The left column is column number 0, the middle column number 1, and the right column is column number 2.\n\n";
    TicTacToe game;
    game.playGame();
    return 0;
}
