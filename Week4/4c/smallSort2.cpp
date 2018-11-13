/***********************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/18/2017
** Description: smallSort.cpp contains the smallSort function, which accepts 3 integer
**              addresses, and sorts the values assigned to the addresses, smallest to largest
***********************************************************************************************/

void swapper(int *, int *);         // Function definition

/************************************************************************************************
** Description: smallSort(int *, int *, int *) is a function that accepts 3 integer addresses
**              and sorts the values stored at those addresses, smallest to largest using the
**              built in swapper() function
************************************************************************************************/

void smallSort2(int *a, int *b, int *c){
    // a points to the memory address of the first int argument passed to smallSort
    // b points to the memory address of the second int argument passed to smallSort
    // c points to the memory address of the third int argument passed to smallSort
    
    // Check if the value stored in the memory address a points to is greater than the value
    // stored in the memory address b points to
    if (*a > *b){
        // If true, use swapper() to swap the values stored in the memory addresses a and b point to
        swapper(a, b);
    }
    
    // Check if the value stored in the memory address a points to is greater than the value
    // stored in the memory address c points to
    if (*a > *c){
        // If true, use swapper() to swap the values stored in the memory addresses a and c point to
        swapper(a, c);
    }
    
    // Check if the value stored in the memory address b points to is less than the value
    // stored in the memory address c points to
    if (*b > *c){
        // If true, use swapper() to swap the values stored in the memory addresses b and c point to
        swapper(b, c);
    }
    
}

/************************************************************************************************
 ** Description: swapper(int *, int *) is a function that accepts 2 integer addresses and swaps
 **              the values stored at those addresses
 ************************************************************************************************/

void swapper(int *num1, int *num2){
    // num1 is the address of the first int value to swap
    // num2 is the address of the second int value to swap
    // swapNum is a placeholder to store the swapped numbers
    int swapNum;
    
    // Swap values stored in the memory addresses num1 and num1 point to
    swapNum = *num1;        // Assign the value stored at the memory address num1 points to, to swapNum
    *num1 = *num2;          // Assign the value stored at the memory address num2 points to, to num1
    *num2 = swapNum;        // Assign the value stored in swapNum to the memory address num2 points to
}
