/********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/28/2017
** Description: T3Reader.hpp is the class specification file for T3Reader objects
*********************************************************************************/

#ifndef T3READER_HPP	// Check if T3READER_HPP has been defined
#define T3READER_HPP	// Define T3READER_HPP

#include "Board.hpp"	// Required to use Board objects
#include <string>	// Required to use String objects
#include <fstream>	// Required to use ifstream objects
#include <cctype>	// Required to use isdigit()

class T3Reader
{
private:
    Board someBoard;	// Tic-Tac-Toe board resulting from the input file
    char currentPlayer;		// Char representing the player who's turn it is

public:
    T3Reader(char);	// Constructor
    bool readGameFile(std::string);	// Function to read file containing moves
};

#endif
