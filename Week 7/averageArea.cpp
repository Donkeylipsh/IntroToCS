/*********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/8/2017
** Description: averageArea.cpp contains the averageArea function that takes as a
**		parameter a vector of Shape-pointers and returns the average area 
**		of the Shapes
*********************************************************************************/

#include <vector>	// Required to use Vectors
#include "Shape.hpp"	// Required to use Shape objects

double averageArea(std::vector<Shape *> shapes){
    // Shapes is a vector of shapes
    int numShapes = shapes.size();	// numShapes is the count of Shapes in the vector
    double total = 0.0;		// total is the sum of all the Shape's areas
    double average;		// average is the average area of the Shapes

    // Add each Shape's area to total 
    for (int i = 0; i < numShapes; i++){
	total += shapes[i]->area();	// Add the area of element i to total
    }

    average = total / numShapes;	// Calculate average

    return average;	// Return the value of average
}
