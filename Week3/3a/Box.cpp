/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Box.cpp is the Box class implementation file.  The Box class describes
**		a Box object with length, width, and height values, and can return the
**		surface area and volume values.
***************************************************************************************/

#include "Box.hpp"

/**************************************************************************************
** Description: Box() is the default constructor for a Box object, which assigns all 
**              data values to 1.0
***************************************************************************************/
Box::Box()
{
    setHeight(1.0);	// Assigns a value of 1.0 to height
    setWidth(1.0);	// Assigns a value of 1.0 to width
    setLength(1.0);	// Assigns a value of 1.0 to length
}

/**************************************************************************************
** Description: Box(double, double, double) constructs a Box object that assigns the
**		input parameters to height, width and length
***************************************************************************************/ 
Box::Box(double boxHeight, double boxWidth, double boxLength)
{
    setHeight(boxHeight);	// Assigns a value of boxHeight to height
    setWidth(boxWidth);		// Assigns a value of boxWidth to width
    setLength(boxLength);	// Assigns a value of boxLength to length
}

/****************************************************************************************
** Description: setHeight(double) assigns the input parameter to the Box's height variable
******************************************************************************************/
bool Box::setHeight(double boxHeight)
{
    bool validData = true;		// Contains result of new height assignment

    if ( boxHeight >= 0.0 )		// Test if parameter sent is a valid value for height
    {  
        height = boxHeight;		// If boxHeight is valid, assign it to height
    }
    else
    {
        validData = false;		// Else, leave height unchanged for invalid values
    }

    return validData;			// Return result of height assignment
}

/****************************************************************************************
** Description:  setWidth(double) assigns the input parameter to the Box's width variable
*******************************************************************************************/
bool Box::setWidth(double boxWidth)
{
    bool validData = true;		// Contains result of new width assignment

    if ( boxWidth >= 0.0 )		// Test if parameter sent is a valid value for width
    {
        width = boxWidth;		// If boxWidth is valid, assign it to width
    }
    else
    {
        validData = false;		// Else, leave width unchanged for invalid values
    }

    return validData;			// Return the result of the width assignment
}

/*****************************************************************************************
** Description: setLength(double) assigns the input parameter to the Box's length variable
******************************************************************************************/
bool Box::setLength(double boxLength)
{
    bool validData = true;		// Contains the result of the new length assignment

    if ( boxLength >= 0.0 )		// Test if parameter sent is a valid value for length
    {
        length = boxLength;		// If boxLength is valid, assign it to length
    }
    else
    {
        validData = false;		// Else, leave length unchnaged for invalid values
    }

    return validData;			// Return the result of the length assignment
}

/*****************************************************************************************
** Description: calcVolume() calculates the volume of the box and returns that value
******************************************************************************************/
double Box::calcVolume()
{
    return ( length * width * height );		// Return the volume of the Box
}

/****************************************************************************************
** Description: valcSurfaceArea() calculates the surface area of the box and returns that value
*****************************************************************************************/
double Box::calcSurfaceArea()
{
    // Return the surface area of the Box
    return ( ( length * width * 2 ) + ( length * height * 2 ) + ( width * height * 2 ) );
}
