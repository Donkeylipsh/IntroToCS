/**********************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Taxicab.hpp is the Taxicab class specification file
***********************************************************************/
#ifndef TAXICAB_HPP		// Check if Taxicab.hpp has already been included
#define TAXICAB_HPP		// If not, define TAXICAB_HPP

/*****************************************************************************************
** Description: The Taxicab class hold values for the Taxicab object's xCoord, yCoord and 
**		distance traveled, and can return and update each value
******************************************************************************************/ 
class Taxicab
{
    private:
        int xCoord,		// xCoord is the current x-coordinate of the Taxicab object
            yCoord,		// yCoord is the current y-coordinate of the Taxicab object
            distanceTraveled;	// distanceTraveled is the total distance teh Taxicab object has traveled

    public:
        Taxicab();		// Constructs a default Taxicab object
        Taxicab(int, int);	// Constructs a Taxicab object with a specified xCoord and yCoord
        int getXCoord();		// Returns the value of xCoord 
        int getYCoord();		// Returns the value of yCoord
	int getDistanceTraveled();	// Returns the value of distanceTraveled
        void moveX(int);		// Increments the xCoord value by the parameter
        void moveY(int);  		// Increments the yCoord value by the parameter

};

#endif
