/********************************************************************
** Author: Colin Van Overschelde
** Date: 10/3/2017
** Description: fileAdder.cpp reads integers from a file, calculates
**              their sum, and writes the sum to "sum.txt"
*********************************************************************/

#include <iostream>
#include <fstream>        // Needed to use files

using namespace std;

int main()
{
    // inputFile is the input file stream
    // outputFile is the output file stream
    // inputName is the name of the input file
    // OUTPUT_NAME is the name of the output file
    // num is the most recent number read from the input file
    // total is the sum of all numbers read from the input file
    ifstream inputFile;
    ofstream outputFile;
    string inputName;
    const string OUTPUT_NAME = "sum.txt";
    int num,
        total = 0;
  
    // Get input filename
    cout << "Please enter your filename." << endl;
    cin >> inputName;

    // Open the input file
    inputFile.open(inputName);
 
    // Check if input file was successfully created
    if (inputFile)
    {
        // Read all values from inputFile
        while (inputFile >> num)
        {   
            // Add num from inputFile to total
            total += num;
        }
        // Close inputFile
        inputFile.close();

        // Open outputFile
        outputFile.open(OUTPUT_NAME);

        // Write total to outputFile
        outputFile << total;

        // Close outputFile
        outputFile.close();
        
        // Display success output
        cout << "result written to sum.txt" << endl;
    }
    else
        // Display error output
        cout << "could not access file" << endl;
      
    return 0;    // False, no errors encountered
}
