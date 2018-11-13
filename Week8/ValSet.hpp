/***************************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: ValSet.hpp is the class specification and implementation for ValSet template objects
**				ValSet objects represent a mathematical set of values of generic type
****************************************************************************************************/

#ifndef VALSET_HPP
#define VALSET_HPP

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define BASE_SIZE 10		// Default arraySize used by default constructor

/***************************************************************************************************
** Description: ValSet template class specification describes objects that represent a mathematical
**				set of values of generic type
****************************************************************************************************/
template <typename T>
class ValSet
{
private:
	T *tPtr;			// Pointer to an array of T objects
	int arraySize;		// Number of elements in the array tPtr points to
	int valueCount;		// Number of elements in the array tPtr points so that have values

public:
	ValSet();								// Default constructor
	ValSet(const T &);						// Copy Constructor
	ValSet<T> &operator=(ValSet<T> &);		// Copy Assignment Overload
	ValSet<T> &operator+(ValSet<T> &);		// Addition operator Overload
	ValSet<T> &operator*(ValSet<T> &);		// Multiplecation operator overload
	ValSet<T> &operator/(ValSet<T> &);		// Division operator overload
	~ValSet();								// Deconstructor
	int size();								// Returns valueCount
	bool isEmpty();							// Returns true if no elements have values
	bool contains(T);						// Returns true if any elements contains the value of T
	void add(T);							// Add T to the array tPtr points to
	void remove(T);							// Removes T from the array tPtr points to
	vector<T> getAsVector();				// Returns a vector of all the elements with values
};

/***************************************************************************************************
** Description: ValSet() is the default constructor for ValSet objects
**				Creates a new dynamic array of T objects, and initializes arraySize and valueCount 
****************************************************************************************************/
template <typename T>
ValSet<T>::ValSet() {
	this->tPtr = new T[BASE_SIZE];	// Create new array in dynamic memory with BASE_SIZE elements
	this->arraySize = BASE_SIZE;	// Initialize the arraySize variable to BASE_SIZE
	this->valueCount = 0;			// Initialise the valueCount variable to 0
}

/***************************************************************************************************
** Description: ValSet(cont T) is the copy constructor for ValSet objects
**				Copies the array the obj.tPtr points to this->tPtr and initializes arraySize and
**				valueCount to the values stored in obj
****************************************************************************************************/
template <typename T>
ValSet<T>::ValSet(const T &obj) {

	this->arraySize = this->valueCount = obj.size();	// Initialize arraySize and valueCount
	this->tPtr = new T[this->arraySize];	// Create a new array in dynamic memory with as many element in obj
	
	// Copy the contents of the array obj.tPtr points to to this->tPtr
	for (int i = 0; i < obj.size(); i++) {
		this->tPtr[i] = obj.tPtr[i];
	}
}

/***************************************************************************************************
** Description: Assignment operator overload deallocates the memory the tPtr currently points to,
**				allocates new memory the appropriate size, and copies the contents of right
****************************************************************************************************/
template <typename T>
ValSet<T>& ValSet<T>::operator=(ValSet<T> &right) {

	// Check if copy isn't the same object
	if (this != &right) {
		// If not, copy right to this

		delete[] this->tPtr;		// Deallocate existsing memory assigned to this->tPtr
		
		this->arraySize = right.arraySize;	// Copy the value of arraySize
		this->valueCount = right.size();	// Copy the value of valueCount
		
		this->tPtr = new T[this->arraySize];	// Allocate new memory for this->tPtr
		
		// Copy the contents of right.tPtr to this->tPtr
		for (int i = 0; i < right.size(); i++) {
			this->tPtr[i] = right.tPtr[i];
		}

	}

	return *this;	// Return the new copy
}

/******************************************************************************************************
** Description: Addition operator overload returns a new ValSet object that contains a tPtr that points
**				to an array containing the mathematic union of two ValSet objects
*******************************************************************************************************/
template <typename T>
ValSet<T>& ValSet<T>::operator+(ValSet<T> &right) {
	
	ValSet<T> *tempValSet = new ValSet<T>;	// Allocate memory for the new ValSet object
	
	int i;	// Loop control variable

	// Copy the contents of the left operand's tPtr array to tempValSet
	for (i = 0; i < this->valueCount; i++) {
		tempValSet->add(tPtr[i]);
	}

	// Copy the contents of the right operand's tPtr array to tempValSet
	for (i = 0; i < right.valueCount; i++) {
		tempValSet->add(right.tPtr[i]);
	}

	return *tempValSet;		// Return a pointer to the new ValSet object
}

/***************************************************************************************************
** Description: Multiplication operator overload returns a new ValSet object that contains a tPtr
**				that points to an array containing the mathematic intersection of two ValSet objects
****************************************************************************************************/
template <typename T>
ValSet<T>& ValSet<T>::operator*(ValSet<T> &right) {
	
	ValSet<T> *tempValSet = new ValSet<T>;	// Allocate memory for the new ValSet object

	int i = 0;		// Loop control variable
	vector<T> rightVector = right.getAsVector();	
// Vector containing the values right.tPtr points to
	typename vector<T>::iterator vBegin = rightVector.begin();	

// Iterator pointing to the first element rightVector
	typename vector<T>::iterator vEnd = rightVector.end();		// Iterator pointing to the just past the last element of rightVector
	typename vector<T>::iterator vFound;		//  Iterator pointing to the location of element being tested

	// Add each value that exists in both arrays to the array tempValSet.tPtr points to
	for (i = 0; i < this->valueCount; i++) {
		vFound = find(vBegin, vEnd, this->tPtr[i]);		// Search for each tPtr value in rightVector
		
		// Check if the value was found
		if (vFound != vEnd) {
			// If so, add it to tempValSet.tPtr
			tempValSet->add(tPtr[i]);
		}
	}

	return *tempValSet;		// Return the new ValSet object
}

/***************************************************************************************************
** Description: Division operator overload returns a new ValSet object that contains a tPtr that points
**				to an array containing the mathematical difference of two ValSet objects
****************************************************************************************************/
template <typename T>
ValSet<T> &ValSet<T>::operator/(ValSet<T> &right) {
	
	ValSet<T> *tempValSet = new ValSet<T>;	// Allocate memory for the new ValSet object

	vector<T> rightVector = right.getAsVector();	// Get Searchable Vector for right.tPtr
	vector<T> thisVector = this->getAsVector();		// Get Searchable Vector for this->tPtr

	int i = 0;	// Loop control variable

	// Add all elements in thisVector that are not in rightVector to tempValSet->tPtr 
	for (i = 0; i < this->valueCount; i++) {
		// Search for each element of thisVector in rightVector
		typename vector<T>::iterator someIterator = find(rightVector.begin(), rightVector.end(), thisVector[i]);

		// Check if match was found
		if (someIterator == rightVector.end()) {
			// If not, add the unmatched value to teh array tempValSet.tPtr points to
			tempValSet->add(this->tPtr[i]);
		}
	}

	// Add all elements in rightVector that are not in thisVector to tempValSet->tPtr 
	for (i = 0; i < right.size(); i++) {
		// Search for each element of rightVector in thisVector
		typename vector<T>::iterator someIterator = find(thisVector.begin(), thisVector.end(), rightVector[i]);
		
		// Check if a match was found
		if (someIterator == thisVector.end()) {
			// If not, add the unmatched value to the array tempValSet.tPtr points to
			tempValSet->add(right.tPtr[i]);
		}
	}

	return *tempValSet;		// Return the new ValSet object
}

/***************************************************************************************************
** Description: ~ValSet is the destructor for ValSet objects, which deallocates the memory allocated
**				to the tPtr pointer
****************************************************************************************************/
template <typename T>
ValSet<T>::~ValSet() {
	delete[] this->tPtr;	// Deallocate memory
}

/***************************************************************************************************
** Description: size() returns the number of elements that contain a value
****************************************************************************************************/
template <typename T>
int ValSet<T>::size() {
	return valueCount;
}

/***************************************************************************************************
** Description: isEmpty() returns true if the ValSet contains no values, and return false otherwise
****************************************************************************************************/
template <typename T>
bool ValSet<T>::isEmpty() {
	// Check if valueCount equals 0
	if (this->valueCount == 0)
		// If yes, then the ValSet is empty, so return true
		return true;
	else
		// If not, then the ValSet is not empty, so return false
		return false;
}

/***************************************************************************************************
** Description: contains(T) takes a parameter of type T and return true if that value is in the ValSet, 
**				and return false otherwise
****************************************************************************************************/
template <typename T>
bool ValSet<T>::contains(T someValue) {
	vector<T> thisVector = this->getAsVector();
	typename vector<T>::iterator locIterator = find(thisVector.begin(), thisVector.end(), someValue);
	if (locIterator == thisVector.end())
		return false;
	else
		return true;
}

/***************************************************************************************************
** Description: add(T) takes a parameter of type T and add that value to the ValSet (if that value 
**				is not already in the ValSet)
****************************************************************************************************/
template <typename T>
void ValSet<T>::add(T someValue) {
	// Check if the element already exists in the array
	if (!this->contains(someValue)) {
		// If not, add the new element to the array this->tPtr points to

		// Check if there are empty elements in the array
		if (this->arraySize > this->valueCount) {
			// If yes, add the new value to the index of the first empty element
			this->tPtr[this->valueCount] = someValue;

			// Increment valueCount to account for the new value
			this->valueCount++;

		}
		else {
			// If not, create a new array twice as large and then add the element

			// Allocate new memory to hold a temporary copy of existsing array
			T *tempArray = new T[valueCount];	

			int i;	// Loop control variable

			// Copy the contents of existing array to the temporary array
			for (i = 0; i < valueCount; i++) {
				tempArray[i] = this->tPtr[i];
			}
			
			// Double the arraySize
			this->arraySize *= 2;

			// Deallocate the existing array
			delete[] tPtr;

			// Allocate memory for the new array and assign it to this->tPtr
			this->tPtr = new T[arraySize];

			// Copy the contents of the temporary array to the new array
			for (i = 0; i < valueCount; i++) {
				this->tPtr[i] = tempArray[i];

			}

			// Deallocate the memory assigned to the temporary array
			delete[] tempArray;

			// Add the new value to the new array at the next available index
			this->tPtr[i] = someValue;

			// Increment the valueCount
			this->valueCount++;

		}
	}
}

/****************************************************************************************************
** Description: remove(T) takes a parameter of type T and remove it from the ValSet (if that value is
**				in the ValSet) by shifting over all of the subsequent elements of the array
*****************************************************************************************************/
template <typename T>
void ValSet<T>::remove(T someValue) {

	//Check if someValue is in the array
	if (this->contains(someValue)) {
		// If yes, remove all instances of it from the array
		vector<T> thisVector = this->getAsVector();

		if (thisVector.size() > 0) {

			typename vector<T>::iterator locIterator = find(thisVector.begin(), thisVector.end(), someValue);

			int i = 0;
			while (locIterator < (thisVector.end() - 1)) {
				typename vector<T>::iterator nextValue = locIterator + 1;
				*locIterator = *nextValue;

				locIterator++;
				i++;
			}

			this->valueCount--;

			for (; i < this->valueCount; i++) {
				this->tPtr[i] = thisVector[i];
			}
		}
		this->remove(someValue);
	}
}

/***************************************************************************************************
** Description: getAsVector() returns a vector (of type T) that contains all of the values in the
**				ValSet and only those values
****************************************************************************************************/
template <typename T>
vector<T> ValSet<T>::getAsVector() {
	// Create a vector large enough to hold all the values
	vector<T> someVector(this->valueCount);

	// Assign each value in teh array this->tPtr points to to someVector
	for (int i = 0; i < this->valueCount; i++) {
		someVector[i] = this->tPtr[i];
	}

	return someVector;	// Return the vector
}

#endif
