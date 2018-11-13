/**********************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/4/2017
** Description: hailstone.cpp accepts an integer value, and returns how many steps a hailstone
                sequence will taken to generate a value of 1
**********************************************************************************************/

using namespace std;

int hailstone(int stone)
{
    // stone is the current value of the hailstone sequence
    // steps counts the number of steps in the hailstone sequence 
    int steps = 0;
    
    // Start while loop
    // loop executes when stone != 1 and > 0
    while( ( stone !=1 ) && ( stone > 0 ) )
    {
        // Increment steps
        steps++; 
        // Check if stone is even
        if ( stone % 2 == 0 )
        {
            // Generate next value in the hailstone sequence using the even formula
            stone /= 2;    // Set stone = stone / 2
        }
        else
        {
	    // Generate next value in the hailstone sequence using the odd formula	
            stone = ( stone * 3 ) + 1;     
        } 
    }
    
    // Return how many times the loop iterated
    return steps;
}
