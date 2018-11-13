/*********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/28/2017
** Description: T3Reader.cpp is the class implementation file for T3Reader objects
**********************************************************************************/

#include "T3Reader.hpp"		// Required to use T3Reader objects

/*******************************************************************************
** Description: Constructor that takes a char parameter that specifies whether 'x'
**		or 'o' should have the first move
*******************************************************************************/
T3Reader::T3Reader(char firstPlayer){
    // Assign the parameter value to the this->currentPlayer
    this->currentPlayer = firstPlayer;
}

/*******************************************************************************
** Description: readGameFile that takes a string parameter that gives the name of 
**		the game file and reads from the file, sending each move to the board.
**		readGameFile returns false if any of the moves is for a square that was 
**		already occupied, or if there are still additional moves in the file 
**		after the game has finished
********************************************************************************/
bool T3Reader::readGameFile(std::string fileName){
    // Create an ifstream object to read from an input file
    std::ifstream inFile;

    // Open the file that has a filename equal to the parameter
    inFile.open(fileName.c_str());

    char readChar;	// The next char read from the file
    int row,		// int value of the char assigned to the next row move
	col;		// int value of the char assigned to the next column move

    // Initialize row and col to -1 to pass first loop
    row = col = -1;

    // Read all chars from inFile
    while ( inFile >> readChar && this->someBoard.gameState() == UNFINISHED ) {
	// Check if the char read is a digit
	if ( isdigit(readChar) ) {
	    // If yes, assign the int value of the char to either row or col
	    
	    // Check if row has been read since last move
	    if ( row == -1 ) {
		// If not, assign int value of readChar to row
		row = readChar - 48; 
	    }
	    else {
		// Assign int value of readChar to col and make the next move
		col = readChar - 48;

		// Make next move
		if ( this->someBoard.makeMove(row, col, this->currentPlayer) ) {
		    // If move was successful, check if the game was won/drawn
		    if ( this->someBoard.gameState() != UNFINISHED ) {
			// If game is over, check if file contains additional moves
			if ( inFile >> readChar ) {
			    // Close the file
			    inFile.close();
			    return false;
			}
		    }

		    // Reset row and col for next move
		    row = col = -1;
		    // Rset player for next move
		    if (tolower(this->currentPlayer) == 'o')
			this->currentPlayer = 'x';
		    else
			this->currentPlayer = 'o';
    		}
		else{
			
		    // If move was unsuccessful, close the file and return false
		    inFile.close();
		    return false;
		}
	    }
	}
    } 

    // After reading all chars from file, close file and return true
    inFile.close();
    return true;
}
