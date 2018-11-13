/**********************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/4/2017
** Description: fallDistance.cpp is a function that takes the falling time as an argument,
                calculates how far an object will fall in that time, and returns that distance
***********************************************************************************************/

#include <cmath>

using namespace std;

double fallDistance(double time)
{
    // time is the time in seconds that the object will be falling
    // distance is the distance in meters that the object will fall
    // GRAVITY is the force of gravity, assigned a constant value of 9.8
    double distance;
    const double GRAVITY = 9.8;

    // Calculate distance the object has fallen
    distance = 0.5 * GRAVITY * pow(time, 2.0);
    
    // Retrun to the calculated distance
    return distance;
}
