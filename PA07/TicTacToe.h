#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

class TicTacToe {
public:
    TicTacToe();  // Constructor
    void displayBoard() const;
    void playerMove();
    void computerMove();
    bool checkForWin() const;
    bool isBoardFull() const;
    void playGame();

private:
    std::vector<std::vector<char> > board; // Added space between brackets
    bool isPlayerTurn;

    bool checkWinCondition(char player) const;
};

#endif
