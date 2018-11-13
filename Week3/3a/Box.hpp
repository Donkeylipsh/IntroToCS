/***********************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Box.hpp is the Box class specification file
************************************************************/

#ifndef BOX_HPP		// Check if Box.hpp has already been included 
#define BOX_HPP		// If not, define BOX_HPP

/***********************************************************
** Description: Box class declaration
************************************************************/
class Box
{
    private:
        double height;		// The height of the box
        double width;		// The width of the box
        double length;		// The length of the box

    public:
        Box();			// Default constructor
        Box(double, double, double);	// Constructor to define size
        bool setHeight(double);		// Assigns a new value to height
        bool setWidth(double);		// Assigns a new value to width
        bool setLength(double);		// Assigns a new value to length
        double calcVolume();		// Returns the valume of the box
        double calcSurfaceArea();	// Returns the surface area of the box
};

#endif
