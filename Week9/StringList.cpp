/********************************************
** Author: Colin Van Overschelde
** Date: 11/21/2017
** Description: StringList.cpp is the class implementation file for StringList objects
**************************************************************/

#include "StringList.hpp"

/*****************************************************************************
** Description: StringList() is the default constructor, which assigns nullptr
** 		to the head ListNode member variable
******************************************************************************/
StringList::StringList(){
    // Assign nullptr to head 
    head = nullptr;
} 

/*****************************************************************************
** Description: StringList(const &StringList) is the copy constructor, which 
** 		copies an existing StringList object to a new StringList obect
******************************************************************************/
StringList::StringList(const StringList &obj){
    // Create a new ListNode using the values stored in obj.head
    // and assign it to this->head    
    head = new ListNode(obj.head->value, obj.head->next);

    // Create a tempObj ListNode to traverse obj->head
    ListNode *tempObj = obj.head;    

    // Create a tempThis ListNode to traverse this->head
    ListNode *tempThis = this->head;    

    // Traverse all nodes of tempObj, i.e. obj.head
    while(tempObj->next != nullptr){
        // Update tempObj to the next node in the list
	tempObj = tempObj->next;

	// Create a new ListNode using the values stored in tempObj
	// and assign it to tempThis->next
	tempThis->next = new ListNode(tempObj->value, tempObj->next);

	// Update tempThis to the next node in the list    
	tempThis = tempThis->next;
    }
} 

/*********************************************************************
** Description: ~StringList() is the destructor for StringList objects
**********************************************************************/
StringList::~StringList(){
    // Create a tempThis ListNode object to traverse this->head    
    ListNode *tempThis = head;

    // Traverse all nodes of tempThis, i.e. this->head
    while(tempThis != nullptr){
	// Create a garbage ListNode pointer and 
	// assign to it the node tempThis points to
	ListNode *garbage = tempThis;

	// Update tempTHis to point to the next node
	tempThis = tempThis->next;

	// Delete the node garbage points to
	delete garbage;
    }
}

/*************************************************************************************
** Description: add(std::string) adds a new node containing the value of the patameter
** 		to the end of the list
**************************************************************************************/
void StringList::add(std::string someString){
    // Check if this->head is empty
    if (head == nullptr)
	// If yes, create a new ListNode with a value of the someString parameter
	// and assign it to this->head 
        head = new ListNode(someString);
    else{
	// If not, add a new ListNode to the end of this->head
	
	// Create a temp ListNode pointer that points to this->head  
        ListNode *temp = head;

        // Traverse all nodes of temp, i.e. this->head
        while(temp->next != nullptr){
	    // Update temp until temp->next == nullptr
	    temp=temp->next;
        }

        // Create a new ListNode with a value of the someString parameter
        // and assigned it to th temp->next, i.e. the end of this->head
        temp->next = new ListNode(someString);

    }
}

/**********************************************************************************
** Description: position(std::string) returns the (zero-based) position in the list
** 		for the first occurrence of the patameter in the list, or -1 if
** 		that value is not in the list
***********************************************************************************/
int StringList::positionOf(std::string someString){
    // position is the index of the node who's value == someString parameter
    int position = 0;
    
    // *someNode is a pointer to this->head that is used to traverse this->head
    ListNode *someNode = this->head;

    // Traverse someNode, i.e. this->head
    while(someNode != nullptr ){
	// Check if the value stored in someNode->value == someString parameter
	if (someString == someNode->value)
	    // If yes, return the value of position
	    return position;
	else{
	    // If not, increment position and step to the next node
	    position++;
	    someNode = someNode->next;
	}
    }

    // If loop completes without returning a position, then someString is not found,
    // so return -1
    return -1;
}

/**************************************************************************************
** Description: setNodeVal(int, std::string) accepts and integer position and sets the 
** 		value of the node at that position to the value of the string parameter
***************************************************************************************/
bool StringList::setNodeVal(int position, std::string someString){
    // counter is the index of the current node
    int counter = 0;    

    // *someNode is a pointer to this-> that is used to traverse this->head
    ListNode *someNode = head;

    // Traverse someNode until you reach the end of the list 
    // or reach the node at index == position
    while(someNode != nullptr && counter < position){
	// Step to the next node of someNode
	someNode = someNode->next;

	// Increment counter
	counter++;
    }

    // Check if loop found position 
    if(counter == position){
	// If yes, set someNode->value to the someString parameter
        someNode->value = someString;

	// Return true
	return true;
    }
    else
	// If not, position is out of range
	// Return false
        return false;
}

/*************************************************************************************
 * Description: getAsVector() returns a vector with the same size, values and order as 
 * 		the StringList
**************************************************************************************/
std::vector<std::string> StringList::getAsVector(){
    // stringVector holds all the string values of each node in the list
    std::vector<std::string> stringVector;

    // someNode is a pointer to this->head that is used to traverse this->head
    ListNode *someNode = head;

    // Traverse someNode, i.e. this->head
    while(someNode != nullptr){
	// Add the value of someNode->value to the end of the vector
	stringVector.push_back(someNode->value);

	// Step to the next node in the list
  	someNode = someNode->next;
    }
    
    // Return the stringVector
    return stringVector;
}
