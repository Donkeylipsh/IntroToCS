/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: PreferredProject.hpp is the class specification file for PreferredProject
**				objects, which is a CustomerProject object
*****************************************************************************************/

#ifndef PREFERRED_PROJECT_HPP
#define PREFERRED_PROJECT_HPP

#include "CustomerProject.hpp"
class PreferredProject :
	public CustomerProject
{
public:
	PreferredProject(double, double, double);
	virtual double billAmount();
};

#endif
