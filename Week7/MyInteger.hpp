/**********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: MyInteger.hpp is the class specification file for MyInteger objects
***********************************************************************************/

#ifndef MY_INTEGER_HPP
#define MY_INTEGER_HPP

class MyInteger {

    private:
	int *pInteger;		// Point to an int value

    protected:

    public:
	MyInteger(int);		// Constructor that accepts an int
	~MyInteger();		// Destructor
	MyInteger(const MyInteger &);	// Copy constructor
	MyInteger& operator=(const MyInteger &);	// Assignment Overload
	void setMyInt(int);	// Function to set the int value pInteger points to
	int getMyInt() const;	// Function to get the int value pInteger points to 
};

#endif
