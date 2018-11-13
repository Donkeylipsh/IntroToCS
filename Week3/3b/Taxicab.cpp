/*******************************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Taxicab.cpp is the Taxicab class implementation file
********************************************************************************/

#include "Taxicab.hpp"
#include <cmath>

/********************************************************************************
** Description: Taxicab() is the default Taxicab constructor creates a Taxicab object 
**		with all data values set to 0
********************************************************************************/
Taxicab::Taxicab()
{
    xCoord = yCoord = distanceTraveled = 0;	// Assign 0 to xCoord, yCoord and distanceTraveled
}

/*******************************************************************************
** Description: Taxicab(int, int) is a constructor that creates a Taxicab object with 
**		input paramaeter values assigned to the xCoord and yCoord variables 
********************************************************************************/
Taxicab::Taxicab(int xPos, int yPos)
{
    xCoord = xPos;		// Assign xPos to xCoord
    yCoord = yPos;		// Assign yPos to yCoord
    distanceTraveled = 0;	// Assign 0 to distanceTraveled
} 

/*******************************************************************************
** Description: getXCoord() returns the current value of xCoord
********************************************************************************/
int Taxicab::getXCoord()
{
    return xCoord;		// Return the current xCoord value
}

/*******************************************************************************
** Description: getYCoord() returns the current value of yCoord
********************************************************************************/
int Taxicab::getYCoord()
{
    return yCoord;		// Return the current yCoord value
}

/*******************************************************************************
** Description: getDistanceTraveled() returns the current value of distanceTraveled
********************************************************************************/
int Taxicab::getDistanceTraveled()
{
    return distanceTraveled;	// Return the current distanceTraveled value
}
/*******************************************************************************
** Description: moveX(int) increments the Taxicab's xCoord value by the input parameter
**		and it's distanceTraveled value by the absolute value of the input
********************************************************************************/
void Taxicab::moveX(int dX)
{
    xCoord += dX;				// Add the value of dX to xCoord
    distanceTraveled += std::abs(dX);		// Add the absolute value of dX to distanceTraveled
}

/*******************************************************************************
** Description: moveY(int) increments the Taxicab's yCoord value by the input parameter
**		and it's distanceTraveled value bu the absolute value of the input
********************************************************************************/
void Taxicab::moveY(int dY)
{
    yCoord += dY;				// Add the value of dY to yCoord
    distanceTraveled += std::abs(dY);		// Add the absolute value of dY to distanceTraveled
}
