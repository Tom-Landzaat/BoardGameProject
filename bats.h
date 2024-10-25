/****************************************************** 
** Program: bats.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class definition that is derived from the 
** event class 
******************************************************/ 
#ifndef BATS_H
#define BATS_H 

#include "event.h"

//Bats Interface
class Bats: public Event
{
public:
    /*********************************************************************   
    ** Function: Bats default constructor
    ** Description: Creates and initializes values in Bats object
    ** Parameters: None 
    ** Pre-Conditions: Bats class created
    ** Post-Conditions: Bats object properly initialized 
    *********************************************************************/
    Bats();
    
    /*********************************************************************   
    ** Function: percept()
    ** Description: redefines percept function (pure virtual in event class)
    ** Parameters: none
    ** Pre-Conditions: board is properly initialized and populated to 
    ** alert users of nearby events
    ** Post-Conditions: Prints the Bats specific percept to console
    *********************************************************************/
    void percept();
};

#endif