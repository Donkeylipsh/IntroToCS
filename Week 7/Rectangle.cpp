/***********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Rectangle.cpp is the class implementation file for Rectangle objects
**		A Rectangle object is a Shape object
************************************************************************************/

#include "Rectangle.hpp"

/**********************************************************************************
** Description: Rectangle() is the default constructor for Rectangle objects, which
**		also calls the Shape default constructor
***********************************************************************************/
Rectangle::Rectangle() : Shape() {
    this->setWidth(0.0);	// Call setWidth to assign a value of 0.0 to width
    this->setLength(0.0);	// Call setLength to assign a vlaue of 0.0 to length
}

/***************************************************************************************
** Description: Rectangle(double, double) is a constructor that assigns parameter values 
**		to length and width, as well as calls the Shape default constructor
****************************************************************************************/
Rectangle::Rectangle(double length, double width) : Shape()
{
    // Check if the length parameter value is valid, i.e. greater than 0.0
    if ( length < 0.0 )
	length = 0.0;	// If not valid, set length to 0.0

    // Check if the width parameter value is valid, i.e. greater than 0.0
    if ( width < 0.0 )
	width = 0.0;	// If not valid, set width to 0.0

    this->setWidth(width);	// Call setWidth to assign the width parameter to this->width
    this->setLength(length);	// Call setLength to assign the length parameter to this->length
}

/**************************************************************************************
** Description: setLength(double) accepts a double value and assigns it to this->length
***************************************************************************************/
void Rectangle::setLength(double length){
    
    // Check if the length parameter contains a valid length value, i.e. greater than 0.0
    if ( length < 0 )
	length = 0.0;	// If not valid, set length to 0.0

    this->length = length;	// Assign the value of length parameter to this->length
}

/************************************************************************************
** Description: setWidth(double) accepts a double value and assigns it to this->width
*************************************************************************************/
void Rectangle::setWidth(double width){

    // Check if the width parameter contains a valid width value, i.e. greater than 0.0
    if ( width < 0.0 )
	width = 0.0;	// If not valid, set width to 0.0

    this->width = width;	// Assign the value of the width parameter to this->width
}

/*********************************************************************************
** Description: area() calculates the area of the Rectangle and returns this value
**********************************************************************************/
double Rectangle::area() const {
    return ( this->length * this->width );	// Calculate the area and return the value
}

/******************************************************************************************
** Description: perimeter() calculates the perimeter of the Rectangle and returns the value
*******************************************************************************************/
double Rectangle::perimeter() const {
    // Calculate the perimeter and return the value
    return ( ( this->length * 2 ) + ( this->width * 2 ) );
}
