/****************************************************** 
** Program: wumpus.cpp
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Redefines member functions inherited from
** event class
******************************************************/ 
#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
Wumpus::Wumpus(){
    this->event_char = 'W';
}
void Wumpus::percept(){
    cout << endl << "You smell a terrible stench." << endl;
}
