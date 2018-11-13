/***********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: MyInteger.cpp is the class implementation file for MyInteger objects
************************************************************************************/

#include "MyInteger.hpp"

/********************************************************************************
** Description: MyInteger(int) is the constructor for MyInteger objects
**		Accepts an integer value and assigns it to a dynamically allocated
**		int that pInteger points to
*********************************************************************************/
MyInteger::MyInteger(int num){
    // Dynamically allocate a new integer that pInteger points to
    pInteger = new int;

    // Assign the parameter value num to the new memory
    *pInteger = num;
}

/********************************************************************************
** Description: ~MyInteger() is the default constructor that frees the dynamic memory
*********************************************************************************/
MyInteger::~MyInteger(){
    // Free the dynamic memory
    delete pInteger;
}

/********************************************************************************
** Description: MyInteger(const MyInteger &) is a copy constructor for MyInteger obejcts
**		Accepts a MyInteger reference parameter and assigns the value it's
**              pInteger points to, to the new dynamically allocated memory pInteger  
*********************************************************************************/
MyInteger::MyInteger(const MyInteger &obj){
    // Dynamically allocate new integer that pInteger points to
    pInteger = new int;

    // Assign the value obj's pInteger points to, to the memory pInteger points to
    *pInteger = obj.getMyInt();

}
/********************************************************************************
** Description: Copy Assignment Overload that free's the existing dynamic integer
**		memory and assigns new dynamic memory to pInteger
*********************************************************************************/
MyInteger& MyInteger::operator=(const MyInteger &right){
    
    // Assign the value right's pInteger points to, to the memory pInteger points to 
    *pInteger = right.getMyInt();

    // Return this updated MyInteger object
    return *this;
}

/********************************************************************************
** Description: setMyInt(int) accepts an integer assigns an integer value and assigns
**		the new value to the memory pInteger points to
*********************************************************************************/
void MyInteger::setMyInt(int num){

    *pInteger = num;

}

/********************************************************************************
** Description:
*********************************************************************************/

int MyInteger::getMyInt() const{

    return *pInteger;
}
