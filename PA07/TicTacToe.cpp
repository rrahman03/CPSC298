#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

TicTacToe::TicTacToe() : isPlayerTurn(true) {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, '~'));
}

void TicTacToe::displayBoard() const {
    for (const auto &row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void TicTacToe::playerMove() {
    int x, y;
    do {
        std::cout << "Please enter grid row number (0-2): ";
        std::cin >> x;
        std::cout << "Please enter grid column number (0-2): ";
        std::cin >> y;
    } while (x < 0 || x > 2 || y < 0 || y > 2 || board[x-1][y-1] != '~');
    board[x-1][y-1] = 'X';
    isPlayerTurn = false;
}

void TicTacToe::computerMove() {
    srand(time(NULL));
    if (!isPlayerTurn) {
        int x, y;
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != '~');
        board[x][y] = 'O';
        isPlayerTurn = true;
    }
}

bool TicTacToe::checkForWin() const {
    return checkWinCondition('X') || checkWinCondition('O');
}

bool TicTacToe::isBoardFull() const {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == '~') {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToe::checkWinCondition(char player) const {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == player && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == player && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

void TicTacToe::playGame() {
    while (!checkForWin() && !isBoardFull()) {
        displayBoard();
        playerMove();
        if (checkForWin()) {
            displayBoard();
            std::cout << "Winner: X" << std::endl;
            return;
        }
        if (!isBoardFull()) {
            computerMove();
            if (checkForWin()) {
                displayBoard();
                std::cout << "Winner: O" << std::endl;
                return;
            }
        }
    }
    if (isBoardFull()) {
        displayBoard();
        std::cout << "Game Over. It's a draw." << std::endl;
    }
}
