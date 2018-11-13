/****************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/17/2017
** Description: findMedian.cpp is a function that takes two parameteres, an array of int
**              and the size of the array, and returns the median of the array
*****************************************************************************************/

#include <algorithm>          // Required to use the sort() function

double findMedian(int numList[], int size){
    // numList[] is the array of int's we want to find the median for
    // size is the number of elements in numList[]
    // median is the median value of numList[] 
    double median; 
    
    // Sort the array from smallest to largest
    std::sort(numList, numList + size);
    
    // Check if there is an even number of elements in numList[]
    if(size % 2 == 0){
        // If true, set median = to the mean of the two middle values 
        median = ( numList[size / 2] + numList[(size / 2) - 1] ) / 2.0;
    }
    else{
        // If false, set the median to the single middle value
        median = numList[size / 2];
    }
    
    // Return the median value of the array    
    return median;
}
