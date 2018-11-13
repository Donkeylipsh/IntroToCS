/***********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Square.cpp is the class implementation file for Square objects
**		A Square is a Rectangel, and a Rectangle is a Shape
***********************************************************************************/

#include "Square.hpp"


/**********************************************************************************
** Description: Square() is the default constructor, which calls the Rectangle default constructor 
***********************************************************************************/
Square::Square() : Rectangle() {
	// Square constructor doesn't initialize any values
}

/****************************************************************************************
** Description: Square(double) is a Square constructor, which passes its parameter to the 
**		Rectangle(double, double) constructor
*****************************************************************************************/
Square::Square(double size) : Rectangle(size, size) {
	// Square(double) constructor uses the Rectangle(double, double) constructor
	// to initialze all values of the Square

}

/***************************************************************************************
** Description: setLength(double) accepts a double value and assigns it to this->length
**		and this->width
****************************************************************************************/
void Square::setLength(double length){
    this->Rectangle::setLength(length);
    this->Rectangle::setWidth(length);	// Assign the parameter value to this->length and this->width
} 

/*************************************************************************************
** Description: setWidth(double) accepts a double value and assigns it to this->length
**		and this->width
**************************************************************************************/
void Square::setWidth(double width) {
    this->Rectangle::setLength(width);
    this->Rectangle::setWidth(width);		// Assign the parameter value to this->length and this->width
}
