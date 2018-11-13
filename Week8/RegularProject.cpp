/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: RegularProject.hpp is the class implementation file for RegularProject
**				objects
*****************************************************************************************/
#include "RegularProject.hpp"


RegularProject::RegularProject(double someHours, double someMaterials, double someTransportation) : CustomerProject(someHours, someMaterials, someTransportation)
{

}

/***************************************************************************************
** Description: billAmount() return the amount to bill for a RegularProject
****************************************************************************************/
double RegularProject::billAmount()
{
	return this->getHours() * 80 + this->getMaterials() + this->getTransportation();
}
