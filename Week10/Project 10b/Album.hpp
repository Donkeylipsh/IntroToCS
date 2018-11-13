/*****************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Album.hpp is the class specification file for Album objects, which are 
**		derrived from LibraryItem
******************************************************************************************/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "LibraryItem.hpp"	// Required to inherit from LibraryItem

class Album : public LibraryItem {
private:
    std::string artist;		// artist of the album
public:
    Album(std::string, std::string, std::string);
    static const int CHECK_OUT_LENGTH = 14;	
    std::string getArtist();
    virtual int getCheckOutLength();
};

#endif
