/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/30/2017
** Description: summer.cpp is a recursive function that takes two parameters - an array 
**		of doubles and the size of the array, and returns the sum of the values
**		stored in the array
***************************************************************************************/

// minSize is used to determine if a valid size value was passed to the function
// all values greater than minSize are valid, all values <= minSize are invalid
#define minSize 0

double summer(double numbers[], int size){
    // sum is the current sum of the values in the array
    double sum = 0;
    
    // Check if a valid size parameter was passed    
    if (size > minSize) {
	// If yes, calculate the sum
	
	// Assign the value stored in numbers[size - 1] to sum
	// First iteration size - 1 = the last element in the array
	// Last iteration size - 1 = the first element in the array
	sum = numbers[size - 1];

	// Check if the recursive function has reached the first element
	if ((size -1) > 0){
	    // Return sum + the value of the next element
	    return sum + summer(numbers, --size);
	}
	else{
	    // Return the value of sum
	    return sum;
	}
    }
    else{
	// When invalid size value is passed, return 0
	return sum;
    }
}
