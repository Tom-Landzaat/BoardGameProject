/****************************************************** 
** Program: event.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class declaration for event class which 
** is an abstract class that contains the specific events:
** wumpus, bats, stalactites and gold.
******************************************************/ 
#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	char event_char;

public:
    /*********************************************************************   
    ** Function: Event()
    ** Description: default constructor for event class
    ** Parameters: none
    ** Pre-Conditions: event object created
    ** Post-Conditions: event object initialized with default values
    *********************************************************************/ 
    Event();
    
    /*********************************************************************   
    ** Function: ~Event()
    ** Description: virtual so child classes can overwrite to free all of 
    ** their individual dynamic memory 
    ** Parameters: none
    ** Pre-Conditions: dynamic memory goes out of scope
    ** Post-Conditions: all dynamic memory in event class and children is freed
    *********************************************************************/ 
    virtual ~Event();

    /*Getter for event char*/
    char get_event_char() const;

    /*********************************************************************   
    ** Function: percept()
    ** Description: pure virtual function which allows all child events to 
    ** print out their own specific warning message when the player is adjacent
    ** to that room
    ** Parameters: none
    ** Pre-Conditions: board is set up and all related event classes
    ** Post-Conditions: warning is printed to the terminal if the user is next 
    ** to a room containing an event
    *********************************************************************/
    virtual void percept()=0;
	
};
#endif