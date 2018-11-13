/**********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Rectangle.hpp is the class specification file for Rectangle objects
**		A Rectangle object is a Shape object
***********************************************************************************/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape{

    private:
	double length,
	       width;

    public:
	Rectangle();	// Default constructor 
	Rectangle(double, double);	// Constructor that assigns double values to length and width
	void setLength(double);		// Assigns a double value to length
	void setWidth(double);		// Assigns a double value to width
	virtual double area() const;	// Returns the area of the Rectangle
	virtual double perimeter() const;	// Returns the perimeter of the Rectangle

};

#endif
