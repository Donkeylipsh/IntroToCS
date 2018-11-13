/***********************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Book.cpp is the class implementation file for Book objects
***********************************************************************************/

#include "Book.hpp"	

/**********************************************************************************
** Description: Book(string, string, string) calls the LibraryItem constructor, passing
**		idn and bookName
***********************************************************************************/
Book::Book( std::string idn, std::string bookName, std::string bookAuthor ) 
: LibraryItem(idn, bookName) {
    this->author = bookAuthor;
}

/**********************************************************************************
** Description: getAuthor() returns the value of the author data member
***********************************************************************************/
std::string Book::getAuthor(){
    return this->author;
}

/**********************************************************************************
** Description: getCheckOutLength() returns the value of the CHECK_OUT_LENGTH data member
***********************************************************************************/
int Book::getCheckOutLength(){
    return this->CHECK_OUT_LENGTH;
}
