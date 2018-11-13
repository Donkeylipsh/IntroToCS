/*****************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/17/2017
** Description: stdDev.cpp is a functation that takes two parameters, an array of Person objects
**		and the size of the array and returns the standard deviation of the Person
**		object's ages
************************************************************************************************/

#include <cmath>		// Needed to use pow() and sqrt()
#include "Person.hpp"		// Needed to use the Person class

double stdDev(Person *people, int size){
    // *people is the array of Person objects to evaluate
    // size is the number of elements in *people
    // totalAge is the sum of all age values for all Persons in the array
    // meanAge is the mean of all age values for all Persons in the array
    // totalDeviation is a value used in teh calculation of the standardDeviation
    // standardDevication is the stardard deviation for the age values of all Persons in the array
    // i is a loop control variable
    double totalAge,
           meanAge, 
           totalDeviation,  
           standardDeviation;
    int i;
    
    // Calculate totalAge
    for(i = 0; i < size; i++){
        totalAge += people[i].getAge();       // Add the value of each Person's age to the totalAge
    }
    
    // Calculate meanAge
    meanAge = totalAge / size;

    // Calculate totalDeviation from mean
    for(i = 0; i < size; i++){
        totalDeviation += pow((people[i].getAge() - meanAge),2.0);      // Add the value of each Person's age minus the mean age squared to totalDeviation 
    }  
    
    // Calculate standardDeviation 
    standardDeviation = sqrt(totalDeviation / size);

    return standardDeviation;		// Retrun the value stored in standardDeviation
}
