/****************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Book.hpp is the class specification file for Book objects, which are derrived
**		from LibraryItem
*****************************************************************************************/

#ifndef BOOK_HPP
#define BOOK_HPP

#include "LibraryItem.hpp"	// Required to inherit from LibraryItem

class Book : public LibraryItem {
private:
    std::string author;

public:
    Book( std::string, std::string, std::string );
    static const int CHECK_OUT_LENGTH = 21;
    std::string getAuthor();
    virtual int getCheckOutLength();
};

#endif
