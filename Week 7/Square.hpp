/**********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Square.hpp is the class specification file for Square objects
**		A Square is a Rectangle, and a Rectangle is a Shape
**********************************************************************************/

#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Rectangle.hpp"

class Square : public Rectangle
{
    public:
	Square();	// Default constructor assigns 0.0 to this->length and this->width
	Square(double);		// Constructor assigns a parameter value to this->length and this->width
	void setLength(double);		// Assigns a parameter value to this->length and this->width
	void setWidth(double);		// Assigns a parameter value to thies->length and this->width
};

#endif
