/****************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Circle.hpp is the class specification file for Circle objects
**		A Circle object is a Shape object
*****************************************************************************/

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
    private:
	double radius;	// Holds the value of the Circle's radius

    public:
	Circle();	// Default constructor assigns value of 0.0 to radius
	Circle(double);		// Constructor for Circle object that accepts a double value
	void setRadius(double);		// Accepts a double value that it assigns to radius
	virtual double area() const;	// Returns the area of the Circle object
	virtual double perimeter() const;	// Returns the perimeter of the Circle object
};

#endif
