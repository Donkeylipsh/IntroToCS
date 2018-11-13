/***************************************************************************
** Author: Colin Van Overschelde
** Date: 11/29/2017
** Description: LibraryItem.cpp is the class implementation file for LibraryItem obejcts
****************************************************************************/

#include "LibraryItem.hpp"

/***************************************************************************
** Description: LibraryItem(string, string) constructs LibraryItem objects and initializes it's members
****************************************************************************/
LibraryItem::LibraryItem(std::string idc, std::string t){
    // Assign idc to this->idCode
    this->idCode = idc;

    // Assign t to this->title
    this->title = t;

    // Assign nullptr to this->checkedOutBy and this->requestedBy
    this->checkedOutBy = NULL;
    this->requestedBy = NULL;

    // Assign ON_SHELF to this->location
    this->location = ON_SHELF;


}

/****************************************************************************
** Description: getIdCode() returns this->idCode
****************************************************************************/
std::string LibraryItem::getIdCode(){
    return this->idCode;
}

/***************************************************************************
** Description: getTitle returns this->title
****************************************************************************/
std::string LibraryItem::getTitle(){
    return this->title;
}

/***************************************************************************
** Description: getLocation returns this->location
****************************************************************************/
Locale LibraryItem::getLocation(){
    return this->location;
}

/***************************************************************************
** Description: setLocation(Locale) assigns someLocale to this->location
****************************************************************************/
void LibraryItem::setLocation(Locale someLocale) {
    this->location = someLocale;
}

/***************************************************************************
** Description: getCheckedOutBy() returns this->checkedOutBy
****************************************************************************/
Patron* LibraryItem::getCheckedOutBy(){
    return this->checkedOutBy;
}

/***************************************************************************
** Description: setCheckedOutBy(Patron) assigns somePatron to this->checkedOutBy
****************************************************************************/
void LibraryItem::setCheckedOutBy(Patron *somePatron){
    this->checkedOutBy = somePatron;
}

/***************************************************************************
** Description: getRequestedBy() returns this->requestedBy
****************************************************************************/
Patron* LibraryItem::getRequestedBy(){
    return this->requestedBy;
}

/***************************************************************************
** Description: setRequestedBy accepts a Patron and assigns it to this->requestedBy
****************************************************************************/
void LibraryItem::setRequestedBy(Patron *somePatron){
    this->requestedBy = somePatron;
}

/***************************************************************************
** Description: getDateCheckedOut() returns this->dateCheckedOut
****************************************************************************/
int LibraryItem::getDateCheckedOut(){
    return this->dateCheckedOut;
}

/***************************************************************************
** Description: setDateCheckedOut accepts an int and assigns is to dateCheckedOut
****************************************************************************/
void LibraryItem::setDateCheckedOut(int someDate) {
    this->dateCheckedOut = someDate;
}
