/// @file main.cpp
/// @brief main function file for Game
/// @author outstanding.student@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>   // defines std::cout, std::cin
#include "Game.h"     // defines Game class

// Main function for Game progam.
// @return 0 in all circumstances
int main()
{
    bool bPlay = true;
    Game game;

    // TODO: WRITE WHILE LOOP TO ASK IF USER WISHES TO PLAY ANOTHER GAME
    while (bPlay)
    {
        game.play(); // invoke play() member function on game object

        std::cout << std::endl;
        char cPlay = 'n';
        std::cout << "Play another game? (y/n)" << std::endl;
        std::cin >> cPlay; // get user input using std::cin

        if (cPlay == 'n' || cPlay == 'N') // complete if statement to check if user does not want to continue
        {
            bPlay = false;
        }
    }

    return 0;
}
