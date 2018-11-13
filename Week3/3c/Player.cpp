/****************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Player.cpp is the implementation file for the Player class
*****************************************************************************************/

#include "Player.hpp"
#include <iostream>

/***************************************************************************************
** Description: Player() is the default Player constructor that assigns "" to name and
**		-1 to points, rebounds, and assists 
****************************************************************************************/  
Player::Player()
{
    name = "";			// Initialize the value of name to ""
    setPoints(-1);		// Initialize the value of points to -1
    setRebounds(-1);		// Initialize the value of rebounds to -1
    setAssists(-1);		// Initialize the value of assists to -1
}

/***************************************************************************************
** Description: Player(string, int, int, int) is Player constructor that assigns input
**		parameter values to name, points, rebounds and assists
****************************************************************************************/
Player::Player(string playerName, int playerPoints, int playerRebounds, int playerAssists)
{
    name = playerName;			// Initialize the value of name to playerName
    setPoints(playerPoints);		// Initialize the value of points to playerPoints
    setRebounds(playerRebounds);	// Initialize the value of rebounds to playerRebounds
    setAssists(playerAssists);		// Initialize the value of assists to playerAssists 
}

/***************************************************************************************
** Description: getName returns the value assigned to name
****************************************************************************************/
string Player::getName()
{
    return name;			// Return the value assigned to name
}

/***************************************************************************************
** Description: setPoints(int) assigns the value of the input parameter to points
****************************************************************************************/
void Player::setPoints(int newPoints)
{
    points = newPoints;			// Assign the value to newPoints to points
}

/**************************************************************************************
** Description: getPoints() returns the value assigned to points
***************************************************************************************/
int Player::getPoints()
{
    return points;			// Return the value of points
}

/****************************************************************************************
** Description: setRebounds(int) assigns the value of the input parameter to rebounds
*****************************************************************************************/
void Player::setRebounds(int newRebounds)
{
    rebounds = newRebounds;		// Assign the value of newRebounds to rebounds 
}

/****************************************************************************************
** Description: getRebounds() returns the value assigned to rebounds
*****************************************************************************************/
int Player::getRebounds()
{
    return rebounds;			// Return the value of rebounds
}

/****************************************************************************************
** Description: setAssists(int) assigns the value of the input paramater to assists
*****************************************************************************************/
void Player::setAssists(int newAssists)
{
    assists = newAssists;		// Assign the balue of newAssists to assists
}

/****************************************************************************************
** Description: getAssists() returns the value assigned to assists
*****************************************************************************************/
int Player::getAssists()
{
    return assists;			// Return the value of assists
}
