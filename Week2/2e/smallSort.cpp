/************************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/4/2017
** Description: smallSort.cpp accepts 3 reference integers assigns the lowest value to the first
                argument, the middle value to the second argument, and the highest value to the
                third argument
************************************************************************************************/

using namespace std;

void swapNumbers(int &swapNum1, int &swapNum2);

/********************************************************************************************
** Description: smallSort accepts 3 reference integers, compares their values, and uses
                swapNumbers to sort them in ascending order 
*********************************************************************************************/  

void smallSort(int &num1, int &num2, int &num3)
{
    // Check if num2 is less than num1
    if ( num2 < num1 )
    {
        // Swap the values of num1 and num2
        swapNumbers(num1, num2); 
    }
    // num1 is now less than num2
    // Check if num3 is less than num1
    if ( num3 < num1 )
    {
        // Swap the values of num1 and num3
        swapNumbers(num1, num3); 
    }
    // num1 is now the lowest value
    // Check if num3 is less than num2
    if ( num3 < num2 )
    {
        // Swap num2 and num3
        swapNumbers(num2, num3);
    }
    // num1 is now the lowest value, num2 is now the middle value, and num3 is now the highest value
}

/***********************************************************************************************
** Description: swapNumbers accepts 2 reference integers, and swaps the values assigned to them
************************************************************************************************/ 
void swapNumbers(int &swapNum1, int  &swapNum2)
{
    // Swapper is a placeholder for the value being swapped
    int swapper = swapNum1;     // Assign the value of swapNum1 to swapper 
    swapNum1 = swapNum2;        // Assign the value of swapNum2 to swapNum1
    swapNum2 = swapper;         // Assign the value of swapper (originallt swapNum1) to swapNum2
}
