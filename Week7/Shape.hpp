/**************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: Shape.hpp is the class specification file for Shape objects
***************************************************************************/

#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape{
    
    public:
	// Shape objects use the default constructor
	Shape(){}
	virtual double area() const = 0;	// Returns the area() of the Shape
	virtual double perimeter() const = 0;	// Returns the perimeter Shape

};

#endif
