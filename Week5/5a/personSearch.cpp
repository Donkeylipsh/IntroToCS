/************************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/21/17
** Description: personSearch.cpp is a function that accepts a const vector of Person objects
**		and a string name.  personSearch will then search the input vector for a Person
**		object that has a name that matches the input.  If found, personSearch returns 
** 		the index of the Person in the vector.  If no match is found, -1 is returned 
************************************************************************************************/

#include <vector>		// Required for using vector objects 
#include "Person.hpp"		// Required for using Person objects

using namespace std;

int personSearch(const vector<Person> people, string name){
  
    int first = 0,	// Index of the first element to compare
	last = people.size() - 1,	// Index of the last element to compare
	middle,			// Index of the current element being compared
	position = -1;		// Index of the element that matches the search term, -1 if no match
    bool found = false;		// Loop control variable 

    // *** Perform Search ***
    // Check to see if match has been found and if the end of the vecotr has been reached
    while ( ( !found ) && ( first <= last ) ){
	// If no match has been found and the end of the vector hasn't been reached, perform search
	
        middle = ( first + last ) / 2;		// Set middle the midpoint between first and last
       
	// Check if the name value of the element at index middle equals the search term	
        if ( people[middle].getName().compare(name) == 0 ){
	    // If match, set found to true and position to middle
            found = true;
            position = middle;
        }
        else if ( people[middle].getName().compare(name) < 0 ){
	    // If name value of element at index middle is less than the search term, set first to middle + 1
	    // This will limit the next search to first half of remaining elements  
            first = middle + 1;
        }
	else {
	    // Else, set last to middle - 1
	    // This will limit the next search to the second half of remaining elements
	    last = middle - 1;
	} 
    }
    
    return position;	// Returns the index of the matching Person or -1 if no match found
}
