/**********************************************************************
** Author: Colin Van Overschelde
** Date: 11/29/2017
** Description: Library.cpp is the class implementation file for Library objects
***********************************************************************/

#include "Library.hpp"

/***********************************************************************
** Description: Library consturcts Library objects and initializes this->currentDate to 0
************************************************************************/ 
Library::Library() {
    // Assign 0 to this->currentDate
    this->currentDate = 0;
} 

/***********************************************************************
** Description: Adds the parameter to this->holdings
************************************************************************/ 
void Library::addLibraryItem(LibraryItem *someItem) {
    // Add someItem to this->holdings vector
    this->holdings.push_back(someItem);
}

/***********************************************************************
** Description: Adds the parameter to this->members
************************************************************************/ 
void Library::addPatron(Patron *somePatron) {
    // Add somePatron to this->members vector
    this->members.push_back(somePatron);
}

/***********************************************************************
** Description: Accepts patronID and ItemID strings and attempts to add the corresponding
**		Patron to the corresponding LibraryItem's requestedBy vector
************************************************************************/ 
std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID) {
    // Check if the ItemID is in the holdings vector
    LibraryItem *someItem = this->getLibraryItem(ItemID); 

    if( someItem ) {
        // If yes, check if patronID is in the members vector
        Patron *somePatron = this->getPatron(patronID);

	if ( somePatron ) {
	    // If yes, check if the item is already checked out
	    Locale someLocation = someItem->getLocation();
	    if( someLocation != CHECKED_OUT ) {
		// If not, check if the item is on hold by another Patron
		if( someLocation == ON_HOLD_SHELF ) {
		    // Then check if the item was on hold for the requesting Patron
		    if ( somePatron->getIdNum() != someItem->getRequestedBy()->getIdNum() ) { 
			return "item on hold by other patron";
		    }
		    else {
			// If not, update requestedBy to NULL
			someItem->setRequestedBy(NULL);
		    }
		}
		 
		//if( someLocation == ON_SHELF ) { 
                    // If yes, update the Library Item's checkedOutBy, dateCheckedOut and Location
                    someItem->setCheckedOutBy(somePatron);
		    someItem->setDateCheckedOut(this->currentDate);
		    someItem->setLocation(CHECKED_OUT);
                        // Update the Patron's checkedOutItems
                    somePatron->addLibraryItem(someItem);

		    // Then return "check out successful"
		    return "check out successful";
		 
	    }
	    else
		return "item already checked out";
	}
	else
	    return "patron not found";
    }
    else
	return "item not found"; 
}

/***********************************************************************
** Description: Accepts an ItemID string and attempts to update the corresponding LibraryItems
**		requestedBy and the Patron's checkedOutItems vector  
************************************************************************/ 
std::string Library::returnLibraryItem(std::string ItemID) {
    // Check if the ItemID is in the holdings vector
    LibraryItem *someItem = this->getLibraryItem(ItemID);
    
    if( someItem ) {
        // If yes, check if the ItemID is checked out
        if( someItem->getLocation() == CHECKED_OUT ) {
            // If yes, update the Patron's checkedOutItems,
            Patron *somePatron = someItem->getCheckedOutBy();
	    somePatron->removeLibraryItem(someItem);

            // Then update the LibraryItem's location depending on whether another Patron has requested it
            Patron *requester = someItem->getRequestedBy();

            if( requester ){
		someItem->setLocation(ON_HOLD_SHELF);
	    }
            else {
		someItem->setLocation(ON_SHELF);
	    }
	
	    // Update the LibraryItem's checkedOutBy to nullptr
	    someItem->setCheckedOutBy(NULL);

	    // Return "return successful"
	    return "return successful"; 
        }
	else
	    return "item already in library";
    }
    else
	return "item not found";
}

/***********************************************************************
** Description: requestLibraryItem(string, string) accepts a patronId and ItemID strings
**		and attempts to add the corresponding Patron to the corresponding LibraryItem
**		requestedBy field
************************************************************************/ 
std::string Library::requestLibraryItem(std::string patronId, std::string ItemID) {
    // Check if the ItemID is in this->holdings
    LibraryItem *someItem = this->getLibraryItem(ItemID);

    if ( someItem ) {
	// If yes, check if the patronId is in this->members
	Patron *somePatron = this->getPatron(patronId);

	if ( somePatron ) {
	    // Get the Patron assigned to requestedBy of someItem
	    Patron *requester = someItem->getRequestedBy();

	    // Check if the requester exists
	    if ( requester ) {
		// Return "item already on hold"
	        return "item already on hold";
	    }
	    else {
		// If not, update the LibraryItem's requestedBy
		someItem->setRequestedBy(somePatron);

		// Check if the LibraryItem is on the shelf
		if ( someItem->getLocation() == ON_SHELF ) { 
		    // Update the LibraryItem's location to ON_HOLD_SHELF
		    someItem->setLocation(ON_HOLD_SHELF);
		}
		    // Return "request successful"
		    return "request successful";
	    }
	}
	else {
	    // If not, return "patron not found"
	    return "patron not found";
	}
    }
    else {
	// If not, return "item not found"
	return "item not found";
    } 
}

/***********************************************************************
** Description: payFine(string, double) accepts a patronID string and payment double and 
**		attempts to reduce the corresponding Patron's fineAmount by payment
************************************************************************/ 
std::string Library::payFine(std::string patronID, double payment){
    // Check if patronID is in this->members
    Patron *somePatron = this->getPatron(patronID);

    // Adjust payment to negative
    if ( payment > 0 ) 
        payment *= -1.0; 

    if ( somePatron ) {
	// If yes, use amendFine to update the Patron's fine
	somePatron->amendFine(payment);

	// Return "payment successful"
	return "payment successful";
    }
    else {
        // If not, return "patron not found"
        return "patron not found";
    }
}

/***********************************************************************
** Description: incrementCurrentDate() increases the date value by 1, and then updates 
**		all Patron's fineAmount member using amendFine()
************************************************************************/ 
void Library::incrementCurrentDate(){
    // Increment this->currentDate
    this->currentDate++;
 
    // Increase each Patron's fines by 10 cents for each overdue LibraryItem
    int size = this->members.size();

    for(int i = 0; i < size; i++) {
	// Get the member's checkOutItems vector
	std::vector<LibraryItem*> someItems = this->members[i]->getCheckedOutItems();

	// Set newFines = 0;
	double newFines = 0.0;

	// Loop through vector
	int itemSize = someItems.size();
	for(int j = 0; j < itemSize; j++){ 
	    // For each item that has checkedOutDate + CHECK_OUT_LENGTH < currentDate
	    // add 0.10 to newFines
	    if ( ( someItems[j]->getDateCheckedOut() + someItems[j]->getCheckOutLength() ) 
		< this->currentDate ) {
		newFines += 0.10;
	    }
	}
	// When loop completes, send newFines to the members->amendFine();
	this->members[i]->amendFine(newFines);
    } 
}

/***********************************************************************
** Description: getPatron(string) accepts a string and returns the corresponding Patron
************************************************************************/
Patron* Library::getPatron(std::string patronID){
    // Check if patronID is in the members vector
    int size = this->members.size();
    Patron *somePatron = NULL;

    for(int i = 0; i < size; i++){
        if ( patronID == this->members[i]->getIdNum() ){
	    somePatron = this->members[i];
	}
    }

    return somePatron;
}

/***********************************************************************
** Description: getLibraryItem(string) accepts a string and returns the corresponding LibraryItem
************************************************************************/ 
LibraryItem* Library::getLibraryItem(std::string ItemID){
    // Check if the ItemID is in the holdings vector
    int size = this->holdings.size();
    LibraryItem *someItem = NULL;

    for(int i = 0; i < size; i++) {
	if( ItemID == this->holdings[i]->getIdCode() ) {
	    someItem = this->holdings[i];
	}
    }

    return someItem;
}
