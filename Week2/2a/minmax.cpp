/*************************************************************************
** Author: Colin Van Overschelde
** Date: 10/3/2017
** Description: minmax.cpp finds the min and max numbers input by the user
**************************************************************************/

// Declare all preprocessor directorives
#include <iostream>

using namespace std;

// Declare all prototypes 

/**********************************************************************
** Description: main() asks the user how many numbers to compare and
                then compares each number input to find the min and max
                numbers input
***********************************************************************/
int main()
{
    // minNum is the lowest number input by the user
    // maxNum is the highest number input by the user
    // inputNum is the last number input by the user
    // numCount is the total count of numbers to compare
    int minNum,
        maxNum,
        inputNum,
        numCount;

    // Get count of numbers to input
    cout << "How many integers would you like to enter?" << endl;
    cin >> numCount;
   
    // Get numbers to compare from user
    cout << "Please enter " << numCount << " integers." << endl;
    cin >> inputNum;
    
    // Set minNum and maxNum to first number input
    minNum = inputNum;
    maxNum = inputNum;
    
    // Use a for loop to get and compare the remaining numbers
    for(int i = 1; i < numCount; i++)
    {
        cin >> inputNum;
        // Compare inputNum to min
        if (inputNum < minNum)
            minNum = inputNum;
        // Compate inputNum to max
        if (inputNum > maxNum)
            maxNum = inputNum;
    }
    // Display Output
    cout << "min: " << minNum << endl;
    cout << "max: " << maxNum << endl;

    return 0;  // False, no errors encountered
}
