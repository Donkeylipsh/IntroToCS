/****************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/30/2017
** Description: Movie.hpp is the class specification file for Movie objects
****************************************************************************************/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "LibraryItem.hpp"

class Movie : public LibraryItem {
private:
    std::string director;
public:
    Movie(std::string mId, std::string mName, std::string mDirector);
    static const int CHECK_OUT_LENGTH = 7;
    std::string getDirector();
    int virtual getCheckOutLength();
};


#endif
