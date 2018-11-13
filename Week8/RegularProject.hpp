/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: RegularProject.hpp is the class specification file for RegularProject
**				objects, which is a CustomerProject object
*****************************************************************************************/

#ifndef REGULAR_PROJECT_HPP
#define REGULAR_PROJECT_HPP

#include "CustomerProject.hpp"
class RegularProject :
	public CustomerProject
{
public:
	RegularProject(double, double, double);
	virtual double billAmount();
};

#endif