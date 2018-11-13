/*****************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Team.cpp is the class implementation file for the Team class
******************************************************************************************/

#include "Team.hpp"

/*****************************************************************************************
** Description: Team(Player, Player, Player, Player, Player) constructs a Team object and
		assigns each input parameter to pointGuard, shootingGuard, smallForward,
                powerForward and center 
******************************************************************************************/ 
Team::Team(Player pg, Player sg, Player sf, Player pf, Player c)
{
    pointGuard = pg;		// Assigns the value of the pg Player parameter to pointGuard
    shootingGuard = sg;		// Assigns the value of the sg Player parameter to shootingGuard
    smallForward = sf;		// Assigns the value of the sf Player parameter to smallForward
    powerForward = pf;		// Assigns the value of the pf Player parameter to powerForward
    center = c;			// Assigns the value of the c Player parameter to center
}

/*****************************************************************************************
** Description: setPointGuard(Player) assigns the value of input parameter to pointGuard
******************************************************************************************/ 
void Team::setPointGuard(Player pg)
{
    pointGuard = pg;			// Assigns the value of the Player parameter to pointGuard
}

/*****************************************************************************************
** Description: getPointGuard() returns the value of pointGuard
******************************************************************************************/ 
Player Team::getPointGuard()
{
    return pointGuard;			// Returns the value of the Player object assigned to pointGuard
}

/*****************************************************************************************
** Description: setShootingGuard(Player) assigns the value of input parameter to shootingGuard
******************************************************************************************/ 
void Team::setShootingGuard(Player sg)
{
    shootingGuard = sg;			// Assigns the value of the Player parameter to shootingGuard
}

/*****************************************************************************************
** Description: getShootingGuard() returns the value of shootingGuard
******************************************************************************************/ 
Player Team::getShootingGuard()
{
    return shootingGuard;		// Returns the value of the Player object assigned to shootingGuard
}

/*****************************************************************************************
** Description: setSmallForward(Player) assigns the value of the input parameter to smallForward
******************************************************************************************/ 
void Team::setSmallForward(Player sf)
{
    smallForward = sf;		// Assigns the value of the Player parameter to smallForward 
}

/*****************************************************************************************
** Description: getSmallForward() returns the value of smallForward
******************************************************************************************/ 
Player Team::getSmallForward()
{
    return smallForward;	// Returns the value of the Player object assigned to smallForward
}

/*****************************************************************************************
** Description: setPowerForward(Player) assigns the value of the input paramater to powerForward
******************************************************************************************/ 
void Team::setPowerForward(Player pf)
{
    powerForward = pf;		// Assigns the value of the Player parameter to powerForward
}

/*****************************************************************************************
** Description: getPowerForward() returns the value of powerForward
******************************************************************************************/ 
Player Team::getPowerForward()
{
    return powerForward;	// Returns the value of the Player object assigned to powerForward
}

/*****************************************************************************************
** Description: setCenter(Player) assigns the value of the input parameter to center
******************************************************************************************/ 
void Team::setCenter(Player c)
{
    center = c;			// Assigns the value of the Player parameter object to center
}

/*****************************************************************************************
** Description: getCenter() returns the value of center
******************************************************************************************/
Player Team::getCenter()
{
    return center;		// Returns the value of the Player object assigned to center
}

/*****************************************************************************************
** Description: totalPoints() calculates the sum of all Player.points values, and returns this value
******************************************************************************************/
int Team::totalPoints()
{
    // Calculate sum of all Player's points and return the value
    return ( pointGuard.getPoints() + shootingGuard.getPoints() + smallForward.getPoints() + powerForward.getPoints() + center.getPoints() );
}
