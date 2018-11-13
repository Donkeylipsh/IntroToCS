/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: CustomerProject.hpp is the class specification file for CustomerProject
**				objects
*****************************************************************************************/

#ifndef CUSTOMER_PROJECT_HPP
#define CUSTOMER_PROJECT_HPP

class CustomerProject
{
private:
	double hours, materials, transportation;
public:
	CustomerProject(double, double, double);
	double getHours();
	void setHours(double);
	double getMaterials();
	void setMaterials(double);
	double getTransportation();
	void setTransportation(double);
	virtual double billAmount() = 0;
};

#endif
