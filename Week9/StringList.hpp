/************************************************************************************
** Author: Colin Van Overschelde
** Date: 11/21/2017
** Description: StringList.hpp is the Class specification file for StringList objects
*************************************************************************************/
#ifndef STRINGLIST_HPP
#define STRINGLIST_HPP
 
#include <string>	// Required to use std::string
#include <vector>	// Required to use std::vector

class StringList{

    protected:
        struct ListNode{
	    std::string value;
	    ListNode *next;
            // ListNode constructor used to create ListNode structs
	    ListNode(std::string s, ListNode *n = nullptr){
	        // Assigns the value of s to value 
		value = s;

		// If an n, parameter is included, assign the value of n to next
		// Otherwise, assign nullptr to n 
	        next = n;
            }
        };
	ListNode *head;

    public:
	StringList();	// Default Constructor
	StringList(const StringList &);		// Copy Constructor
	~StringList();		// Default Destructor
	void add(std::string);		// Adds a new ListNode to the list
	int positionOf(std::string);	// Returns the position of the first node containing a value 
	bool setNodeVal(int, std::string);	// Assigns a new value to a target node
	std::vector<std::string> getAsVector();		// Retuns a vector containing each node value 
};

#endif
