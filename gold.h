/****************************************************** 
** Program: gold.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class definition that is derived from the 
** event class 
******************************************************/ 
#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

//Gold Interface
class Gold: public Event
{
public:
    /*********************************************************************   
    ** Function: Gold default constructor
    ** Description: Creates and initializes values in Gold object
    ** Parameters: None 
    ** Pre-Conditions: Gold class created
    ** Post-Conditions: Gold object properly initialized 
    *********************************************************************/
    Gold();

    /*********************************************************************   
    ** Function: percept()
    ** Description: redefines percept function (pure virtual in event class)
    ** Parameters: none
    ** Pre-Conditions: board is properly initialized and populated to 
    ** alert users of nearby events
    ** Post-Conditions: Prints the Gold specific percept to console
    *********************************************************************/
    void percept();
};
#endif