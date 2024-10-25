/****************************************************** 
** Program: wumpus.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class definition that is derived from the 
** event class 
******************************************************/ 
#ifndef WUMPUS_H
#define WUMPUS_H 
#include "event.h"

//Wumpus Interface
class Wumpus: public Event
{
public:
    /*********************************************************************   
    ** Function: Wumpus()
    ** Description: Default Constructor for Wumpus class
    ** Parameters: None
    ** Pre-Conditions: Wumpus class created 
    ** Post-Conditions: Wumpus object is properly initialized
    *********************************************************************/
    Wumpus();

    /*********************************************************************   
    ** Function: percept()
    ** Description: redefines percept function (pure virtual in event class)
    ** Parameters: none
    ** Pre-Conditions: board is properly initialized and populated to 
    ** alert users of nearby events
    ** Post-Conditions: Prints the Wumpus specific percept to console
    *********************************************************************/
    void percept();

};
#endif