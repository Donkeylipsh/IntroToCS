/*****************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Circle.cpp is the class implementation file for Circle objects
******************************************************************************/

#include "Circle.hpp"

#define PI 3.141592	// Decalre a constant value for Pi

/********************************************************************************
** Description: Circle() : Shape() is the default constructor for Circle objects
**		which is a Shape, so the Shape default constructor is also called
*********************************************************************************/
Circle::Circle() : Shape()
{
    this->setRadius(0.0);	// Assign a value of 0.0 to this->radius
}

/********************************************************************************
** Description: Circle(double) : Shape() accepts a double value and constructs a 
**		Circle object with a radius equal to the double, which is a
**		Shape, so the Shape default constructor is also called
*********************************************************************************/ 
Circle::Circle(double radius) : Shape()
{
    // Check if radius parameter value is valid, i.e. greater than 0.0
    if ( radius < 0.0 )
	radius = 0.0;	// If not valid, set radius to 0.0
 
    this->setRadius(radius);	// Set this->radius to the radius value
}

/***************************************************************************************
** Description: setRadius(double) accepts a double value, and assigns it to this->radius
****************************************************************************************/
void Circle::setRadius(double radius) {

    // Check if radius parameter value is valid, i.e. greater than 0.0
    if ( radius < 0.0 )
	radius = 0.0;	// If not valid, set radius to 0.0

    this->radius = radius;	// Assign the value of the double parameter to this->radius
}

/*****************************************************************************
** Description: area() calculates the area of the Circle object and returns it
******************************************************************************/
double Circle::area() const {
    return PI * this->radius * this->radius;	// Return the area of the Circle
}

/***************************************************************************************
** Description: perimeter() calculates the perimeter of the Circle object and returns it
****************************************************************************************/
double Circle::perimeter() const {
    return 2.0 * PI * this->radius;	// Return the perimeter of the Circle
}
