/**********************************************************************************
** Author: Colin Van Overschelde
** Date: 10/21/2017
** Description: personSort.cpp is a function that accepts an array of Persons, and
**		the size of the array, and sorts the array from oldest to youngest
***********************************************************************************/

#include "Person.hpp"		// Required to work with Person objects

void personSort(Person people[], int size){
    bool madeAswap;	// Loop control variable 
    
    // Start bubble sort
    do{
	madeAswap = false;	// Reset the loop control variable

	// Step through each Person in the array
	for (int i = 0; i < (size - 1); i++){
	    
	    // Check if current Person is younger than the next Person
	    if ( people[i].getAge() < people[i+1].getAge() ){
		
		// If true, swap the two elements in the array
		Person temp( people[i].getName(), people[i].getAge() );
		people[i] = people[i+1];
		people[i+1] = temp;
		
		// Set loop control variable to true, indicating that array is not yet fully sorted
		madeAswap = true;
	    }
	}
    }while (madeAswap);		// When madeAswap = false, the array is sorted from oldest to youngest
}
