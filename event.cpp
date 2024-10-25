/****************************************************** 
** Program: event.cpp
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Event function definitions which allow for
** initialization of no event in a room and allow other
** classes to access the event character to determine the
** type of event in said room.
******************************************************/ 
#include "event.h"

#include <iostream>

using namespace std;

//Event Implementation


Event::Event(){
    //cout << "Event()" << endl;
    this->event_char = ' ';
}

Event::~Event(){
    //cout << "~Event()" << endl;
}

char Event::get_event_char() const{
    return this->event_char;
}
