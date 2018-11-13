/*******************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Patron.cpp is the class implementation file for Patron objects
********************************************************************************/

#include "Patron.hpp"

/*******************************************************************************
** Description: Patron(string, string) accepts 2 strings and initiates the Patron data members
********************************************************************************/
Patron::Patron(std::string idn, std::string n){
    this->idNum = idn;

    this->name = n;

    this->fineAmount = 0.0;
}

/*******************************************************************************
** Description: getIdNum() returns this->idNum
********************************************************************************/
std::string Patron::getIdNum(){
    return this->idNum;
}

/*******************************************************************************
** Description: getName() returns this->name
********************************************************************************/
std::string Patron::getName(){
    return this->name;
}

/*******************************************************************************
** Description: getCheckedOutItems() returns this->checkedOutItems
********************************************************************************/
std::vector<LibraryItem*> Patron::getCheckedOutItems(){
    return this->checkedOutItems;
}

/*******************************************************************************
** Description: addLibraryItem(LibraryItem*) accepts a pointer to a LibraryItem and
**		adds it to this->checkedOutItems
********************************************************************************/
void Patron::addLibraryItem(LibraryItem* b){
    this->checkedOutItems.push_back(b);
}

/*******************************************************************************
** Description: removeLibraryItem(LibraryItem*) accepts a pointer to a LIbraryItem and
**		removes it from this->checkedOutItems 
********************************************************************************/
void Patron::removeLibraryItem(LibraryItem* b){
    // Loop through this->checkedOutItems to find b
    int size = this->checkedOutItems.size();
    
    for(int i = 0; i < size; i++){
	if( b == this->checkedOutItems[i] ){
	    this->checkedOutItems.erase( this->checkedOutItems.begin() + i );
	    i = size;
	}
    } 

    
}

/*******************************************************************************
** Description: getFineAmount() returns this->fineAmount
********************************************************************************/
double Patron::getFineAmount(){
    return this->fineAmount;
}

/*******************************************************************************
** Description: amendFine(double) accepts a double value and adds it to this->fineAmount
********************************************************************************/
void Patron::amendFine(double amount){
    // Add amount to this->fineAmount
    this->fineAmount += amount;
}
