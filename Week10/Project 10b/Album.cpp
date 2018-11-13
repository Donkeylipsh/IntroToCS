/*****************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Album.cpp is the class implementation file for Album objects 
******************************************************************************************/

#include "Album.hpp"

/*****************************************************************************************
** Description: Album(string, string, string) calls the LibraryItem constructor, passing
**		the aId and aName parameters.  And then assigns aArtist to this->artist
******************************************************************************************/
Album::Album(std::string aId, std::string aName, std::string aArtist) 
: LibraryItem(aId, aName) {
    this->artist = aArtist;
}

/*****************************************************************************************
** Description: getArtist() returns this->artist
******************************************************************************************/
std::string Album::getArtist(){
    return this->artist;
}

/*****************************************************************************************
** Description: getCheckoutLength() returns this->CHECK_OUT_LENGTH
******************************************************************************************/
int Album::getCheckOutLength(){
    return this->CHECK_OUT_LENGTH;
}
