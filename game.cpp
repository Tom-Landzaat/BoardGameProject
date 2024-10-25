/****************************************************** 
** Program: game.cpp
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Definition of member functions for game class
** contains how to display the game and how to accept user input
** to control player movement also determines win/loss.
******************************************************/ 
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
	this->awake = false;
	this->gold = false;
	this->loss = false;
	this->victory = false;
	this->confusion_counter = 0;
}

Game::~Game(){
	//Game destructor
	//Your code here:

}

void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;
	this->num_arrows = 3; 	//start with 3 arrows

	// Finish the remaining...
	//Your code here:
	
	// Create the game board: 2D vector of Room objects
	for (int i = 0; i < length; i++){  
	vector<Room> row_vec;  
	for (int j = 0; j < width; j++)   
		row_vec.push_back(Room());  
	board.push_back(row_vec); 
	} 
	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	for(int i = 0; i < 7; i++){
		int row_idx;
		int col_idx;
		do{
			row_idx = rand() % this->length;
			col_idx = rand() % this->width;
		}while(!board[row_idx][col_idx].is_empty());
		if(i == 0){
			board[row_idx][col_idx].assign(new Gold());
		}
		if(i == 1){
			board[row_idx][col_idx].assign(new Wumpus());
		}
		if(i == 2 || i == 3){
			board[row_idx][col_idx].assign(new Bats());
		}
		if(i == 4 || i == 5){
			board[row_idx][col_idx].assign(new Stalactites());
		}
		if(i == 6){
			board[row_idx][col_idx].set_player_loc_true();
		}
	}
}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "

			//else, print "*"

			//Fix the following
			cout << " ";
		
			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			
			//else, 
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
			if(this->debug_view){
				if(this->board[i][j].get_player_loc()){
					cout << "*";
					cout << " ||";
					continue;
				}
 				if(!this->board[i][j].is_empty()){
 					this->board[i][j].print_event();
					cout << " ||";
				}
				else
					cout << "  ||";
			}
			else{
				if(this->board[i][j].get_player_loc()){
					cout << "*";
					cout << " ||";
					continue;
				}
				else
					cout << "  ||";
			}
		}	

		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

void Game::init_pos(){
	for(int i = 0; i < this->length; ++i){
		for(int j = 0; j < this->width; ++j){
			if(this->board[i][j].get_player_loc()){
			this->x_pos = i;
			this->y_pos = j;
			this->x_start = i;
			this->y_start = j;
			}
		}
	}
}

bool Game::check_win() const{
	//check if game over/win
	//Your code here:
	if(victory){
		cout << "\n" << "You killed the Wumpus!" << "\n" << "You won the game!" << "\n" << endl;
		return true;
	}
	else if(gold && ((x_pos == x_start)	&& y_pos == y_start)){
		cout << "\n" << "You escaped with the gold!" << "\n" << "You won the game!" << "\n" << endl;
		return true;
	}
	//if gold is true and player loc = player start
	return false;
}

void Game::move_up() {
	//move player up
	//Your code here:
	if(this->x_pos > 0){
		this->board[x_pos][y_pos].set_player_loc_false();
		this->board[x_pos-1][y_pos].set_player_loc_true();
		this->x_pos--;
	}
	return;

}

void Game::move_down() {
	//move player down
	//Your code here:
	if(this->x_pos < length - 1){
		this->board[x_pos][y_pos].set_player_loc_false();
		this->board[x_pos+1][y_pos].set_player_loc_true();
		this->x_pos++;
	}
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:
	if(this->y_pos > 0){
		this->board[x_pos][y_pos].set_player_loc_false();
		this->board[x_pos][y_pos-1].set_player_loc_true();
		this->y_pos--;
	}
	return;
}

void Game::move_right() {
	//move player right
	//Your code here:
	if(this->y_pos < width - 1){
		this->board[x_pos][y_pos].set_player_loc_false();
		this->board[x_pos][y_pos+1].set_player_loc_true();
		this->y_pos++;
	}
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	if(this->awake){
		int counter = rand() % 4;
		if(counter !=0){
			for(int i = 0; i < this->length; ++i){
				for(int j = 0; j < this->width; ++j){
					if(!board[i][j].is_empty()){
					char a = this->board[i][j].get_event();
						if(a == 'W'){
							/*Delete event at x,y positon (i,j)*/
							this->board[i][j].clear_room();
						}
					}
				}
			}
		int row_idx;
		int col_idx;
		do{
			row_idx = rand() % this->length;
			col_idx = rand() % this->width;
		/*If there is an event in the random room or the player is in the random room, repick random room*/
		}while(!(board[row_idx][col_idx].is_empty()) || (board[row_idx][col_idx].get_player_loc()));
			
		/*Assign Wumpus to valid room*/
		board[row_idx][col_idx].assign(new Wumpus());	
		}
	}
	this->awake = false;
	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	if(this->num_arrows > 0){
		this->num_arrows--;
		char dir = get_dir();
		//Your code here:
		switch(dir){
			case 'w':
				Game::arrow_up();
				break;
			case 'a':
				Game::arrow_left();
				break;
			case 's':
				Game::arrow_down();
				break;
			case 'd':
				Game::arrow_right();
				break;
		}
	}
	else
		cout << "No arrows remaining..." << endl;
}

void Game::arrow_up(){
	char temp;
	for(int i = 1; i < 4; i++){
		if(x_pos-i < 0){
			this->awake = true;
			return;
		}
		if(!this->board[x_pos-i][y_pos].is_empty()){
			/*Get the event character of the room the arrow is in*/
			temp = this->board[x_pos-i][y_pos].get_event();
			if(temp == 'W'){
				this->victory = true;
				return;
			}
		}
	}
	/*If the arrow misses the wumpus, it wakes up for one turn*/
	this->awake = true;
	return;
}

void Game::arrow_down(){
	char temp;
	for(int i = 1; i < 4; i++){
		if(i+x_pos > length - 1){
			this->awake = true;
			return;
		}
		if(!this->board[x_pos+i][y_pos].is_empty()){
			temp = this->board[x_pos+i][y_pos].get_event();
			if(temp == 'W'){
				this->victory = true;
				return;
			}
		}
	}
	this->awake = true;
	return;
}

void Game::arrow_left(){
	char temp;
	for(int i = 1; i < 4; i++){
		if(y_pos-i < 0){
			this->awake = true;
			return;
		}
		if(!this->board[x_pos][y_pos-i].is_empty()){
			temp = this->board[x_pos][y_pos-i].get_event();
			if(temp == 'W'){
				this->victory = true;
				return;
			}
		}
	}
	this->awake = true;
	return;
}

void Game::arrow_right(){
	char temp;
	for(int i = 1; i < 4; i++){
		if(y_pos+i > width - 1){
			this->awake = true;
			return;
		}
		if(!this->board[x_pos][y_pos+i].is_empty()){
			temp = this->board[x_pos][y_pos+i].get_event();
			if(temp == 'W'){
				this->victory = true;
				return;
			}
		}
	}
	this->awake = true;
	return;
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	if(this->confusion_counter == 0)
		switch(c){
			case 'w':
				Game::move_up();
				break;
			case 'a':
				Game::move_left();
				break;
			case 's':
				Game::move_down();
				break;
			case 'd':
				Game::move_right();
				break;
		}
	else{
		this->confusion_counter--;
		switch(c){
		case 's':
			Game::move_up();
			break;
		case 'd':
			Game::move_left();
			break;
		case 'w':
			Game::move_down();
			break;
		case 'a':
			Game::move_right();
			break;
	}
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){


	Game::set_up(w, l);
	Game::init_pos();
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == false && this->loss == false){
	//for(int i = 0; i < 5; i++){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		Game::percept_warning();
		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		Game::event_triggered();
		Game::wumpus_move();

	}
	return;
}
void Game::percept_warning(){
	if(x_pos-1 >= 0){
		if(!board[x_pos-1][y_pos].is_empty()){
			board[x_pos-1][y_pos].print_percept();
		}
	}
	if(x_pos+1 <= (length - 1)){
		if(!board[x_pos+1][y_pos].is_empty()){
			board[x_pos+1][y_pos].print_percept();		
		}
	}
	if(y_pos-1 >=0){
		if(!board[x_pos][y_pos-1].is_empty()){
			board[x_pos][y_pos-1].print_percept();
		}
	}
	if(y_pos+1 <= (width - 1)){
		if(!board[x_pos][y_pos+1].is_empty()){
			board[x_pos][y_pos+1].print_percept();
		}
	}		

}
void Game::event_triggered(){
	int chance = -1;
	if(!this->board[x_pos][y_pos].is_empty()){
		char a = this->board[x_pos][y_pos].get_event();
		if(a == 'W'){//Wumpus event
			cout << endl << "The Wumpus is hungry afterall..." << endl << endl;
			cout << "\n"<< "You lost..." << endl << endl;
			this->loss = true;
		}
		if(a == 'S'){//Stalactite event
			chance = rand() % 2;
			if(chance == 1){
				cout << endl << "Next time wear a helmet..." << endl << endl;
				cout << "\n"<< "You lost..." << endl << endl;
				this->loss = true;
			}
		}
		if(a == 'G'){//Gold event
			cout << endl << "You picked up the gold..." << endl << endl;
			this->gold = true;
			this->board[x_pos][y_pos].clear_room();
		}
		if(a == 'B'){//Bat event
			cout << endl << "Bats swarm you..." << endl << endl;
			this->confusion_counter = 5;
		}
	}
}

void Game::board_size(){
	int l = 0, w = 0, d_int = -1;
	bool d = false;
	while(l < 4 || l > 60){
		cout << "Enter desired board length (4-60): ";
		cin >> l;
	}
	while(w < 4 || w > 60){
		cout << "Enter desired board width (4-60): ";
		cin >> w;
	}
	while(d_int < 0 || d_int > 1){
		cout << "Enter 1 for wallhacks or 0 for normal mode: ";
		cin >> d_int;
	}
	if(d_int == 0)
		d = false;
	if(d_int == 1)
		d = true;
	this->length = l;
	this->width = w;
	this->debug_view = d;
}

int Game::get_length(){
	return this->length;
}
int Game::get_width(){
	return this->width;
}
bool Game::get_debug(){
	return this->debug_view;
}