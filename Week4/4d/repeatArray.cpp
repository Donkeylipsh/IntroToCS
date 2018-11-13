/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/18/2017
** Description: repeatArray.cpp takes two parameters - a reference to a point to a
** 		dynamically allocated array of doubles, and the size of that array.
**		The function replaces the original array with an array twice as large,
**		with the values from teh original array appearing twice. 
***************************************************************************************/

#include <cstdlib>		// Required to check for NULL

void repeatArray(double *&array, int size){
    // Check to see if NULL reference was passed 
    if(array != NULL){
	// If not NULL, repeatArray
	
	// Create new dynamic array on the heap that is twice the size of the input array  
        double *temp = new double[(size * 2)];
        
	// Copy values of input array to temp array
        for(int i = 0; i < size; i++){
            temp[i] = temp[i + size] = array[i];
        }
	
	// Release the input array from memory 
        delete [] array;
        array = NULL;

	// Assign a new array on the heap that is twice the size of the input array to the input reference
        array = new double[(size * 2)];

	// Copy values of temp array to new array that exists at the input reference memory location
        for(int i = 0; i < (size * 2); i++){
            array[i] = temp[i];
        }
    
	// Release the temp array from memory
        delete [] temp;
        temp = NULL;
    }
}
