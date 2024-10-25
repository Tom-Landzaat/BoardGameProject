/****************************************************** 
** Program: bats.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Child of event class using public inheritance 
** has unique character and member functions to differentiate
******************************************************/ 
#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation
Bats::Bats(){
    this->event_char = 'B';
}
void Bats::percept(){
    cout << endl << "You hear wings flapping." << endl;
}