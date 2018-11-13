/**************************************************************************
** Author: Colin Van Overschelde
** Date: 11/28/2017 
** Description: Board.hpp is the class specification file for Board objects
***************************************************************************/

#ifndef BOARD_HPP	// Check if BOARD_HPP has been defined already
#define BOARD_HPP	// Define BOARD_HPP

#include <cctype>	// Required for tolower()

#define BOARD_SIZE 3

// Define an enum for values of gameState
enum GameStateValue { X_WON, O_WON, DRAW, UNFINISHED }; 

/*************************************************************************
** Description: Board object class specification
*************************************************************************/
class Board {
private:
    char gameBoard[BOARD_SIZE][BOARD_SIZE];	// 2-d array for board positions
    GameStateValue currentGameState;		// Contains the value of the current game state
    void updateGameState(char);			// Used by makeMove() to update currentGameState

public:
    Board();		// Default constructor
    bool makeMove(int, int, char);	// Assigns char param to gameBoard[int][int]
    GameStateValue gameState();		// Returns the currentGameState value
};

#endif
