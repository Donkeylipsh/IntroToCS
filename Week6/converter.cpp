/*************************************************************************************************
** Author: Colin Van Overschelde
** Date: 10/31/2017
** Description: colinConverter.cpp contains two function, binToDec and decToBin.  binToDec accepts
**				a string contianing a binary number and returns an integer containing the decimal
**				value of the string.  decToBin accepts an integer and returns a string containing
**				the binary equivalent of the integer decimal value
**************************************************************************************************/

#include <string>           // Required to work with strings
#include <cmath>            // Required to use the pow function

#define BASE 2
#define ONE "1"
#define ZERO "0"

using namespace std;

/***************************************************************************************************
** Description: binToDec(string) is a recursive function that takes a a C++ string of 1's and 0's 
**		representing a binary number, and returns the equivalent integer value
****************************************************************************************************/
int binToDec(string bin){
    // bin is a string that contains the binary number to convert to decimal
    // num is the leading character of bin that will be evalutated for it's integer value
    // numInt is the decimal conversion of num 
    // remaining is the substring that remains after evaluating the first character of bin
    // index is a loop control variable
    char num = bin[0];
    int numInt;
    string remaining = "";
    int index = 1;

    // Convert the character value to the appropriate integer value
    // Check if num = '0'
    if (num == '0')
	// If true, assign 0 to numDec
	numInt = 0;
    else
	// Else, assign 1 to numDec
	numInt = 1;

    // Check if the leading character is the last character in the string
    if (bin.length() > 1)
    {
	// If not, calculate the decimal value of numInt
	
	// Calculate the value of the exponent
	int exponent = bin.length() - 1;

	// Calculate the decimal value of numInt
	int value = numInt * pow(BASE, exponent);

	// Assign the remaining charactesr of bin to remaining
	for ( ; index < bin.length(); index++){
	    // Add the next character to remaining
	    remaining += bin[index];
	}   

	// Return value + the value returned by the next recursive call to binToDec
	// Recursive call to binToDec calculates the decimal value of the next character in bin
	return value + binToDec(remaining);
    }
    else{
 	// If num is the last character in bin, return numInt
 	return numInt;
    }
}

/************************************************************************************************
** Description: decToBin(unsigned) is a recursive function that takes a positive integer as a 
**		parameter and returns a C++ string of '1's and '0's that make up the binary 
**		representation of that number
*************************************************************************************************/
string decToBin(unsigned dec){
    
    // dec is the integer value of the number to convert
    // bin is the binary representation of dec that the function returns 
    // value is the calculated value of the next binary character
    // remaining is the decimal value remaining after processing the current binary digit
    //           remainig is the value that each recursive call passes to decToBin(unsigned) 
    string bin;
    unsigned value;
    unsigned remaining;

    // Check if the value passed is less than 2, which is the base case
    // A value less than 2 means we are processing the last binary digit
    if( dec >= BASE ){
	// If true, recursively process the largest possible binary digit for dec       
	
	// Set value = to the binary value of the largest possible binary digit
	value = dec % BASE;
	
	// Check value stored in value to assigned the appropriate binary value to bin  
	if (value == 1)
	    // If true, set the value of bin to ONE
	    bin = ONE;
	else
	    // If false, set the value of bin to ZERO
	    bin = ZERO;

	// Calculate the remaining decimal value to convert
	remaining = dec / BASE;
	
	// Recursively call decToBin(unsigned) to obtain the remaining binary digits
	return decToBin(remaining) + bin;
    }
    else{
	// If false, process the last binary digit for dec
	
	// Check vale stored in dec to assign the appropriate binary value to bin
	if (dec == 1)
	    // If true, set the value of bin to ONE
	    bin = ONE;
	else
	    // If false, set the value of bin to ZERO
	    bin = ZERO;
	
	// Return the last binary character
	return bin;
    }
}
