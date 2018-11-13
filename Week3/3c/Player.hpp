/***********************************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Player.hpp is the class declaration file for the Player class
************************************************************************************/
#ifndef PLAYER_HPP		// Check if Player has already been included
#define PLAYER_HPP		// If not, define PLAYER_HPP

#include <string>

using namespace std;

/**********************************************************************************
** Description: Player class describes Player objects
***********************************************************************************/
class Player
{
    private:
	string name;		// name is the name of the player
	int points;		// points is the points the player has scored
	int rebounds;		// rebounds is the rebounds the player has gathered
	int assists;		// assists is the ssists the player has disributed
    
    public:
	Player();		// Default constructor for Player objects
	Player(string, int, int, int);		// Constructor that assigns name, points, rebounds and assists
	string getName();		// Returns the name of the Player
	void setPoints(int);		// Assigns the parameter value to points
	int getPoints();		// Returns the points value of the Player
	void setRebounds(int);		// Assigns the parameter value to rebounds
	int getRebounds();		// Returns the rebounds value of the Player
	void setAssists(int);		// Assigns the parameter value to assists
	int getAssists();		// Returns the assists value of the Player
};

#endif
