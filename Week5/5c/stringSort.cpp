/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/21/2017
** Description: stringSort.cpp is a function that accepts an array of strings, and the
**		size of the array, and sorts the arry in dictionary order using a built
**		in function compareStrings() to compare 2 strings
***************************************************************************************/

#include <string> 	// Required to work with strings
#include <cctype>	// Required to use toupper() 

using namespace std;

bool compareStrings(string, string);

/*****************************************************************************************
** Description: stringSort(string [], int) accepts an array of strings, array, and an int
**		size, and stors the array in dictionary order.
******************************************************************************************/
void stringSort(string array[], int size){
    // array is the input string array
    // size is the number of elements in array
    // startScan is the index of the first element to compare
    // minIndex is the index of the string with the lowest value
    // minValue is the value of the string with the lowest value
    int startScan = 0,
	minIndex;
    string minValue;

    // Start sorting by stepping through each element in array
    for (startScan = 0; startScan < (size - 1); startScan++){
	// Set the minIndex to the current element being sorted
        minIndex = startScan;
	// Set the minValue to the current element being sorted
	minValue = array[startScan];

	// Step through the remaining elements and test their values 
	for (int index = startScan + 1; index < size; index++){
	    
	    // Use the compareStrings() function to check if the value of the 
	    // element being tested is lower than the minValue
	    if (compareStrings(array[index], minValue)){
		
		// If true, set the value element being tested to the minValue 
	        minValue = array[index];
		// Set the minIndex to the index of the elment that is being tested
		minIndex = index;
	    }
	}
	
	// After comparing each value to find the minValue, swap the element being sorted
	// with the element with the minValue.  
	array[minIndex] = array[startScan];
	array[startScan] = minValue;
    }
}

/********************************************************************************************
** Description: compareStrings(string, string) accepts two string values and returns true if
**		the value of the first string is lower than the value of the second.  And
**		returns false otherwise
*********************************************************************************************/
bool compareStrings(string candidate, string currentMin){
    // Candidate is the string we are testing
    // currentMin is the value candidate is compared to
    // newMin is true when candidate < currentMin, false otherwise
    // areEqual is a loop control variable that stops the loop when inequal characters are compared
    // index is a loop control variable 
    // currentMinChar is the current character from the currentMin string
    // currentTestChar is the current character from the candidate string
    bool newMin = false;
    bool areEqual = true;
    int index = 0;
    char currentMinChar, currentCandidateChar;

    // Start comparing characters of the two strings
    do{

	// Set currentMinChar to uppercase equivalent of the character at currentMin[index]
	currentMinChar = toupper(currentMin.at(index));
	// Set currentCandidateChar to uppercase equivalent of the char at currentCandidateChar[index]
	currentCandidateChar = toupper(candidate.at(index));
	
	// Check if currentMinChar > currentCandidateChar
	if (currentMinChar > currentCandidateChar){

	    // If true, then the value of candidate is less than the value of currentMin
	    // Set newMin to true
            newMin = true;
	    // Set areEqual to false to exit loop
	    areEqual = false;
        }
	// Check if currentMinChar < currentCandidateChar
	else if ( currentMinChar < currentCandidateChar ){
	    // If true, then the value of currentMin is less than the value of candidate
	    // Set areEqual to false to exit loop
	    areEqual = false;
	}
        // Increment index
        index++;

    // Continue loop until inequal characters are found or the end of a string is reached
    }while(areEqual && ( index < candidate.length() && index < currentMin.length() ));
    
    // Check if loop exited due to end of string by checking if they are still equal
    if(areEqual){

	// If true check if candidate is shorter than currentMin
	if ( candidate.length() < currentMin.length() ){
	    // If true, candidate has a lower value than currentMin
	    // Set newMin = true 
	    newMin = true;
	}
    }    

    // Return the bool value of newMin, true means candidate is less than currentMin
    return newMin;
}
