/*******************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/4/2014
** Description: numGuess.cpp gets an integer from the user, and then asks the user to guess
**              the input integer, using a loop to repeat until the user correctly guesses
**              the input integer.  The program then prints how many guess it took
********************************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // answer is the number the user is trying to guess
    // guessCount is the count of guesses
    // currentGuess is the last guess number input
    // gameWon controls the game loop.  When gameWon is true the game will exit the loop 
    int answer,
        guessCount = 0,
        currentGuess;
    bool gameWon = false;

    // Get number for the player to guess.
    cout << "Enter the number for the player to guess." << endl;
    cin >> answer;

    // Ask for first guess
    cout << "Enter your guess." << endl;
    
    // Start loop
    do{
        // Increment guessCount
         guessCount++;

        // Get currentGuess from user
	cin >> currentGuess;

        // Compare currentGuess to answer
        if ( currentGuess == answer )
        {
            gameWon = true;       // The answer has been guessed, so exit the loop  
        }
        else if ( currentGuess > answer )
        {
            cout << "Too high - try again." << endl;       // Ask the user to guess again
        }
        else
        {
            cout << "Too low - try again." << endl;        // Ask the user to guess again
        }

    }while( !gameWon );      //  Exit loop if currentGuess == answer

    // Display number of tries
    cout << "You guessed it in " << guessCount << " tries." << endl;

    // Return false, no errors encountered 
    return 0;
}
