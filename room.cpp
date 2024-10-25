/****************************************************** 
** Program: room.cpp
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Function definitions for member functions which 
** check is the room contains and event, can assign events or 
** trigger percepts() when a user is adjacent to a room with an event.
******************************************************/ 
#include "room.h"

using namespace std;

//Room Implementation
Room::Room(){
    //cout << "Room()" << endl;
    this->e = nullptr;
    this->player_loc = false;
}

Room::~Room(){
    
    if(this->e != nullptr){
        delete this->e;
        this->e = nullptr;
    }
}

bool Room::is_empty() const{
    if(this->e == nullptr)
        return true;
    return false;
}

void Room::assign(Event *new_e){
    this->e = new_e;
}

void Room::print_event() const{
    char a = e->get_event_char();
    cout << a;
}
char Room::get_event() const{
    char a = e->get_event_char();
    return a;
}

bool Room::get_player_loc() const{
    return this->player_loc;
}
void Room::set_player_loc_true() {
    this->player_loc = true;
}
void Room::set_player_loc_false() {
    this->player_loc = false;
}

void Room::print_percept(){
    e->percept();
}

void Room::clear_room(){
    if(this->e != nullptr){
        delete e;
        e = nullptr;
    }
}