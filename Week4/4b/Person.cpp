/********************************************************************************
** Author: Colin Van Overschelde
** Date: 10/17/2017
** Description: Person.cpp is the class implementation file for the Person class
*********************************************************************************/

#include "Person.hpp"

/***********************************************************************************
** Description: Persion(string, double) constructs a Person object and initializes
**		the name and age values to the input parameters
**		n is a string value that is assigned to name
**		a is a double value that is assigned to age
************************************************************************************/   
Person::Person(string n, double a){
    name = n;		// Initialize name to n
    age = a;		// Initialize age to a
}

/**********************************************************************************
** Description: getName() returns the value stored in name
***********************************************************************************/ 
string Person::getName(){
    return name;
}

/**********************************************************************************
** Description: getAge() returns the value stored in age
***********************************************************************************/
double Person::getAge(){
    return age;
}
