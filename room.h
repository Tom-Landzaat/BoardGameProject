/****************************************************** 
** Program: room.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class declaration for room which contains 
** events. Each element of the 2d vector is type room.
******************************************************/ 
#ifndef ROOM_H
#define ROOM_H 

#include "event.h"
#include <iostream>

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
	Event* e;
    bool player_loc;
public:
    /*********************************************************************   
    ** Function: Default constructor for Room class
    ** Description: Creates and initializes Room object
    ** Parameters: none
    ** Pre-Conditions: Room class created 
    ** Post-Conditions: Room object is created and initialized with default values
    *********************************************************************/
    Room();

    /*********************************************************************   
    ** Function: ~Room()
    ** Description: Frees all dynamic memory inside the Room class
    ** Parameters: none
    ** Pre-Conditions: dynamic memory goes out of scope
    ** Post-Conditions: All dynamic memory is freed, no memory leaks from room class.
    *********************************************************************/
    ~Room();
    /*Room& operator=(const Room&);//AOO
    Menu(const Room&);//CC*/

    /*********************************************************************   
    ** Function: is_empty()
    ** Description: Returns T/F if the room event pointer is pointing to 
    ** nullptr or an event with a random memory address
    ** Parameters: none
    ** Pre-Conditions: 2d vector of rooms is created, accessing room in bounds
    ** Post-Conditions: T is returned if the room *e points to nullptr
    ** false if there is a valid memory address being pointed to
    *********************************************************************/
    bool is_empty() const;

    /*********************************************************************   
    ** Function: assign(Event*)
    ** Description: Allows us to randomly assign the rooms events (all rooms
    ** default at pointing to nullptr)
    ** Parameters: A pointer to an event
    ** Pre-Conditions: event class is set up aswell as the board
    ** Post-Conditions: The room is question now has its event pointer pointing 
    ** to the memory address of an event
    *********************************************************************/
    void assign(Event*);	

    /*********************************************************************   
    ** Function: print_event()
    ** Description: Prints out the event character of a certain event at
    ** the specified room.
    ** Parameters: none
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: prints the event character at the given room
    *********************************************************************/
    void print_event() const;

    /*********************************************************************   
    ** Function: get_event()
    ** Description: returns the character event at a specified room
    ** Parameters: none
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: event character at certain room is returned 
    *********************************************************************/
    char get_event() const;

    /*********************************************************************   
    ** Function: get_player_loc()
    ** Description: returns the bool T/F if the player is in the specified room
    ** Parameters: none
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: returns true if player is in the room or false if not
    *********************************************************************/
    bool get_player_loc() const;

    /*********************************************************************   
    ** Function: set_player_loc_true()
    ** Description: sets the player location bool to true at a given room
    ** Parameters: none
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: specified room has player location set to true
    *********************************************************************/
    void set_player_loc_true();

    /*********************************************************************   
    ** Function: set_player_loc_false()
    ** Description: sets the player location bool to false at a given room
    ** Parameters: none
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: specified room has player location set to false
    *********************************************************************/
    void set_player_loc_false();

    /*********************************************************************   
    ** Function: print_percept()
    ** Description: Calls the event function percept 
    ** Parameters: none
    ** Pre-Conditions: event class and board set up 
    ** Post-Conditions: event percept function is called
    *********************************************************************/
    void print_percept();

    /*********************************************************************   
    ** Function: clear_room()
    ** Description: frees the dynamic memory in a given room, essentially
    ** deletes the event from the room and resets it to nullptr, no event
    ** Parameters: none
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: all dynamic memory is freed and room is empty
    *********************************************************************/
    void clear_room();

};

#endif