/****************************************************** 
** Program: stalactites.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class definition that is derived from the 
** event class 
******************************************************/ 
#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

//Stalactites Interface

class Stalactites: public Event
{
public:
    /*********************************************************************   
    ** Function: Stalactites default constructor
    ** Description: Creates and initializes values in Stalactite object
    ** Parameters: None 
    ** Pre-Conditions: Stalactite class created
    ** Post-Conditions: Stalactite object properly initialized 
    *********************************************************************/
    Stalactites();

    /*********************************************************************   
    ** Function: percept()
    ** Description: redefines percept function (pure virtual in event class)
    ** Parameters: none
    ** Pre-Conditions: board is properly initialized and populated to 
    ** alert users of nearby events
    ** Post-Conditions: Prints the Stalactite specific percept to console
    *********************************************************************/
    void percept();
};
#endif
