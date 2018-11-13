/****************************************************************************
** Author: Colin Van Overschelde
** Date: 10/17/2017
** Description: Person.hpp is the class specification file for Person class
****************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>		// Needed to use string variables

using namespace std;

class Person
{
    private:
        string name;       // name is the name of the Person
        double age;        // age is the age of the Person

    public:
        Person(string, double);        // Constructs a Person object and initializes the data members
        string getName();              // Retuns the value stored in name
        double getAge();               // Returns the value stored in age
};
#endif
