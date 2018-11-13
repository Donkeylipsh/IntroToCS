/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: RegularProject.hpp is the class implementation file for RegularProject
**				objects
*****************************************************************************************/
#include "PreferredProject.hpp"


PreferredProject::PreferredProject(double someHours, double someMaterials, double someTransportation) : CustomerProject(someHours, someMaterials, someTransportation)
{

}

/***************************************************************************************
** Description: billAmount() return the amount to bill for a RegularProject
****************************************************************************************/
double PreferredProject::billAmount()
{
	double hours = this->getHours();

	if (hours > 100)
		hours = 100;

	return this->getHours() * 80 + this->getMaterials() * 0.85 + this->getTransportation() * 0.90;
}
