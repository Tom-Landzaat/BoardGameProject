/****************************************************** 
** Program: stalactites.cpp
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Redefines functions for the stalactites class
** as a derived event class
******************************************************/ 
#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation
Stalactites::Stalactites(){
    this->event_char = 'S';
}
void Stalactites::percept(){
    cout << endl << "You hear water dripping." << endl;
}