/***********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/29/2017
** Description: Board.cpp is the class implementation file for Board objects
***********************************************************************************/

#include "Board.hpp"	// Required for Board objects

/*********************************************************************************
** Description: Board() constructs a Board object, initilizes all values to ' ' and
**		assigns UNFINISHED to this->currentGameState
*********************************************************************************/
Board::Board() {
    // Initialize all values of this->gameBoard to ' '
    for ( int i = 0; i < BOARD_SIZE; i++ ) {	// Loop though each row

	for ( int j = 0; j < BOARD_SIZE; j++ ) {	// Loop through each column of the row
	    this->gameBoard[i][j] = ' ';	// Assign '' to the array location [i][j]
	}
    }
}

/*********************************************************************************
** Description: makeMove(int, int, char) two ints and a char (either 'x' or 'o') as
**		parameters, representing the x and y coordinates of the move and
**		which player's turn it is
*********************************************************************************/
bool Board::makeMove(int row, int column, char player) {
    if (this->gameState() == UNFINISHED) {
        // Check if move location and player are valid
        if ( this->gameBoard[row][column] == ' ' 
           && ( tolower(player) == 'x' || tolower(player) == 'o' ) ) {
	    // If move is valid, make move and update game state to check for winner/draw
	
	    // Make move
	    this->gameBoard[row][column] = tolower(player);


	    // Return true, indicating successful move
	    return true;
        }
        else {
	    // If move is invalid, return false
	    return false;
        }
    }
    else{
	return false;
    }
}

/*********************************************************************************
** Description: gameState() returns the value of this->currentGameState
*********************************************************************************/
GameStateValue Board::gameState() {
    	
    // isDraw is a control variable that only executes code if a draw is detected
    bool isDraw = true;

    // i is a loop control variable
    int i = 0;

    // Check if winner by row by looping through each row
    while ( i < BOARD_SIZE ) {
	// Check if all columns in the row row have the same value
	if ( this->gameBoard[i][0] == this->gameBoard[i][1] == this->gameBoard[i][2] ) {
	    // If all equal player, check which player won the game
	    if ( this->gameBoard[i][0] == 'x' ) {
	        // Assign X_WON to this->currentGameState
	        return X_WON;
	    }
	    else if ( this->gameBoard[i][0] == 'o' ){
	        // Assign O_WON to this->currentGameState
	        return O_WON;
	    }
	}
	    
	// Increment i to check next row in loop
	i++;
    }

    // Check if winner by column by looping through each column
    i = 0;		// Reset loop control variable
    while ( i < BOARD_SIZE ) {
        // Check if all rows in the column have the same value
        if ( this->gameBoard[0][i] == this->gameBoard[1][i] == this->gameBoard[2][i] ) {
            // If all equal player, check which player won the game
	    if ( this->gameBoard[0][i] == 'x' ) {
	        // Assign X_WON to this->currentGameState
	        return X_WON;
	    }
	    else if ( this->gameBoard[0][i] == 'o' ) {
	        // Assign O_WON to this->currentGameState
	        return O_WON;
	    }
	}
	// Increment i to check the next column in th eloop
	i++;
    }

    // Check if winner by first diagonal
    if ( this->gameBoard[0][0] == this->gameBoard[1][1] == this->gameBoard[2][2] ) {

            // If all equal player, check which player won the game
	    if ( this->gameBoard[0][0] == 'x' ) {
	        // Assign X_WON to this->currentGameState
	        return X_WON;
	    }
	    else if ( this->gameBoard[0][0] == 'o' ) {
	        // Assign O_WON to this->currentGameState
	        return O_WON;
	    }
		 
    }

    // Check if winner by second diagonal
    if ( this->gameBoard[0][2] == this->gameBoard[1][1] == this->gameBoard[2][0] ) {
	
        // If all equal player, check which player won the game
	if ( this->gameBoard[0][2] == 'x' ) {
	    // Assign X_WON to this->currentGameState
	    return X_WON;
	}
	else if ( this->gameBoard[0][2] == 'o' ) {
	    // Assign O_WON to this->currentGameState
	    return O_WON;
	} 
    }

    // Check if there is a draw by looping through each gameBoard value
    for ( i = 0; i < BOARD_SIZE; i++ ) {
	for ( int j = 0; j < BOARD_SIZE; j++ ) {
	    // Check if the value is still ' '
	    if ( this->gameBoard[i][j] == ' ' ) {
	        // If yes, then there is no draw
		isDraw = false; 
	    } 
        } 
    }

    // Check if the game was a draw
    if ( isDraw ) {
        return DRAW; 
    }

    // Return UNFISHED
    return UNFINISHED;
}
