/**************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/15/2017
** Description: CustomerProject.hpp is the class implementation file for CustomerProject
**				objects
*****************************************************************************************/

#include "CustomerProject.hpp"

/***************************************************************************************
** Description: CustomerProject() is the default constructor for CustomerProject objects
**				assigns the parameter values to hours, materials and transportation
****************************************************************************************/
CustomerProject::CustomerProject(double someHours, double someMaterials, double someTransportation) {
	this->hours = someHours;
	this->materials = someMaterials;
	this->transportation = someTransportation;
}

/***************************************************************************************
** Description: getHours() returns the value of hours
****************************************************************************************/
double CustomerProject::getHours() {
	return hours;
}

/***************************************************************************************
** Description: setHours() assigns a parameter value to hours
****************************************************************************************/
void CustomerProject::setHours(double someHours) {
	this->hours = someHours;
}

/***************************************************************************************
** Description: getMaterials() returns the value of materials
****************************************************************************************/
double CustomerProject::getMaterials() {
	return this->materials;
}

/***************************************************************************************
** Description: setMaterials() assigns a parameter value to materials
****************************************************************************************/
void CustomerProject::setMaterials(double someMaterials) {
	this->materials = someMaterials;
}

/***************************************************************************************
** Description: getTransportation() returns the value of transportation
****************************************************************************************/
double CustomerProject::getTransportation() {
	return this->transportation;
}

/***************************************************************************************
** Description: setTransporation() assigns a parameter value to transporation
****************************************************************************************/
void CustomerProject::setTransportation(double someTransportation) {
	this->transportation = someTransportation;
}