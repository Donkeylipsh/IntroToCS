/************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/10/2017
** Description: Team.hpp is the class declaration file for Team class
**************************************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include "Player.hpp"

class Team
{
    private:
	Player pointGuard,		// pointGuard is the team's Point Guard player
	       shootingGuard,		// shootingGuard is the team's Shooting Guard player
	       smallForward,		// smallForward is the team's Small Forward player
	       powerForward,		// powerForward is the team's Power Forward player
	       center;			// center is the team's Center player

    public:
	Team(Player, Player, Player, Player, Player);		// Constructor that assigns Players to each position
	void setPointGuard(Player);		// setPointGuard assigns a new Player to pointGuard
	Player getPointGuard();			// getPointGuard returns the pointGuard value
	void setShootingGuard(Player);		// setShootingGuard assigns a new Player to shootingGuard
	Player getShootingGuard();		// getShootingGuard returns the shootingGuard value
	void setSmallForward(Player);		// setSmallForward assigns a new Player value to smallForward
	Player getSmallForward();		// getSmallForward returns the smallForward value
	void setPowerForward(Player);		// setPowerForward assigns a new Player value to the powerForward
	Player getPowerForward();		// getPowerForward returns the powerForward value
	void setCenter(Player);			// setCenter assigns a new Player value to center
	Player getCenter();			// getCenter returns the center value
	int totalPoints();			// Calculates the sum of points for each Player, and returns the value
};

#endif
