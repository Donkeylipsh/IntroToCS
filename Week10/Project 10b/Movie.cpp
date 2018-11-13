/******************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Movie.cpp is the class implementation file for Movie objects
******************************************************************************************/

#include "Movie.hpp"

/****************************************************************************************
** Description: Movie(string, string, string) accepts 3 string values, and calls LibraryItem
**		passing mId and mName 
*****************************************************************************************/
Movie::Movie(std::string mId, std::string mName, std::string mDirector)
: LibraryItem(mId, mName) {
    this->director = mDirector;
}

/****************************************************************************************
** Description: getDirector() returns this->director
*****************************************************************************************/
std::string Movie::getDirector(){
    return this->director;
}

/****************************************************************************************
** Description: getCheckOutLength() returns this->CHECK_OUT_LENGTH
*****************************************************************************************/
int Movie::getCheckOutLength(){
    return this->CHECK_OUT_LENGTH;
}
