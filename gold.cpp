/****************************************************** 
** Program: gold.cpp
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Redefines member functions inherited from 
** event class
******************************************************/ 
#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation
Gold::Gold(){
    this->event_char = 'G';
}
void Gold::percept(){
    cout << endl << "You see a glimmer nearby." << endl;
}