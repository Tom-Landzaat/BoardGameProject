/****************************************************** 
** Program: game.h
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Class declaration for game which is the all encompassing 
** class for this assignment, game contains rooms and each room 
** contains events.
******************************************************/ 
#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector <vector <Room> > board;
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	int x_pos;				//current player pos (left to right)
	int y_pos;				//current player pos (up and down)
	int x_start;			//starting player pos
	int y_start;			//starting player pos
	bool loss;				//true when you lose
	bool gold;				//true when player picked up gold
	bool awake;				//true when wumpus is awake
	bool victory;			//true when user wins
	int confusion_counter;	// >0 when confused by bats

public:

	//suggested functions:
	/*********************************************************************   
    ** Function: Game()
    ** Description: default constructor for game class assigns default values
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: game object created and initialized 
    *********************************************************************/
	Game();

	/*********************************************************************   
    ** Function: ~Game()
    ** Description:  frees all dynamic memory in gmae class
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: all dynamic memory is freed 
    *********************************************************************/
	~Game();

	/*********************************************************************   
    ** Function: set_up()
    ** Description: Initializes the board to specified size and determines
    ** the random location of events and player starting location 
    ** Parameters: two integers that are width and length
    ** Pre-Conditions: Width and length are initialized
    ** Post-Conditions: game basics are set up, events and location
    *********************************************************************/
	void set_up(int, int);

	/*********************************************************************   
    ** Function: display_game()
    ** Description: prints the grid to the screen with only the player location
    ** for normal mode or all event locations too for debug mode
    ** Parameters: none
    ** Pre-Conditions: board is set up
    ** Post-Conditions: current game state displayed to user with num arrows
    *********************************************************************/
	void display_game() const;

	/*********************************************************************   
    ** Function: check_win()
    ** Description: checks if the player has won or lost the game, if so 
    ** continue to the end game screen and end the program gracefully
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: program is ended if the game is over or continues if not
    *********************************************************************/
	bool check_win() const;

	/*********************************************************************   
    ** Function: get_dir()
    ** Description: gets the direction entered by the user and calls the 
    ** appropriate function
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: user input is recieved and calls moving function
    *********************************************************************/
	char get_dir();

	/*********************************************************************   
    ** Function: wumpus_move()
    ** Description: if the player misses an arrow the wumpus wakes up, if the
    ** wumpus is awake it has a 75% chance to move to an empty room and 25% to stay
    ** Parameters: none
    ** Pre-Conditions: board is fully set up
    ** Post-Conditions: if awake, wumpus has a chance to move
    *********************************************************************/
	void wumpus_move();

	/*********************************************************************   
    ** Function: fire_arrow()
    ** Description: fires an arrow in a chosen direction that travels up to 
    ** 3 rooms if it enters the wumpus room the player wins
    ** Parameters: none  
    ** Pre-Conditions: board set up properly
    ** Post-Conditions: check if the rooms the arrow is heading will hit 
    ** the wumpus and act accordingly
    *********************************************************************/
	void fire_arrow();

	/*********************************************************************   
    ** Function: move_up()
    ** Description: moves the user up and changes variables
    ** Parameters: none
    ** Pre-Conditions: board set up
    ** Post-Conditions: updates y position of player
    *********************************************************************/
	void move_up();

	/*********************************************************************   
    ** Function: move_down()
    ** Description: moves the user down and changes variables
    ** Parameters: none
    ** Pre-Conditions: board set up
    ** Post-Conditions: updates y position of player
    *********************************************************************/
	void move_down();

	/*********************************************************************   
    ** Function: move_left()
    ** Description: moves the user left and changes variables
    ** Parameters: none
    ** Pre-Conditions: board set up
    ** Post-Conditions: updates x position of player
    *********************************************************************/
	void move_left();

	/*********************************************************************   
    ** Function: move_right()
    ** Description: moves the user right and changes variables
    ** Parameters: none
    ** Pre-Conditions: board set up
    ** Post-Conditions: updates x position of player
    *********************************************************************/
	void move_right();

	/*********************************************************************   
    ** Function: move()
    ** Description: takes the directed move and updates variables to 
    ** represent the move
    ** Parameters: character of which direction to move
    ** Pre-Conditions: board set up
    ** Post-Conditions: updates positon variables of player
    *********************************************************************/
	void move(char);

	/*********************************************************************   
    ** Function: get_input()
    ** Description: get and error checks user movement input
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns character of user input
    *********************************************************************/
	char get_input();

	/*********************************************************************   
    ** Function: play_game()
    ** Description: Calls all game functions in the correct order to operate
    ** a seemless game experience
    ** Parameters: width, length and T/F for debug mode
    ** Pre-Conditions: none
    ** Post-Conditions: board is set up, debug mode is determined and game 
    ** in itself is now working and looping
    *********************************************************************/
	void play_game(int, int, bool);

	/*********************************************************************   
    ** Function: init_pos()
    ** Description: takes user starting position and stores it in x,y coords
    ** for the current position and starting for gold-escape case
    ** Parameters: none
    ** Pre-Conditions: player location assigned
    ** Post-Conditions: player location stored in x,y coords
    *********************************************************************/
	void init_pos();

	/*********************************************************************   
    ** Function: event_triggered()
    ** Description: Checks if the user is in a room that has an event, if so
    ** perform the correct actions according to the the event character 
    ** Parameters: none
    ** Pre-Conditions: board is set up
    ** Post-Conditions: event actions are performed
    *********************************************************************/
	void event_triggered();

	/*********************************************************************   
    ** Function: arrow_down
    ** Description: fires arrow down which passes through 3 rooms
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: game ends if arrow enters room with the wumpus otherwise
    ** wakes the wumpus up
    *********************************************************************/
	void arrow_down();

	/*********************************************************************   
    ** Function: arrow_up
    ** Description: fires arrow up which passes through 3 rooms
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: game ends if arrow enters room with the wumpus otherwise
    ** wakes the wumpus up
    *********************************************************************/
	void arrow_up();

	/*********************************************************************   
    ** Function: arrow_left
    ** Description: fires arrow left which passes through 3 rooms
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: game ends if arrow enters room with the wumpus otherwise
    ** wakes the wumpus up
    *********************************************************************/
	void arrow_left();

	/*********************************************************************   
    ** Function: arrow_right
    ** Description: fires arrow right which passes through 3 rooms
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: game ends if arrow enters room with the wumpus otherwise
    ** wakes the wumpus up
    *********************************************************************/
	void arrow_right();

	/*********************************************************************   
    ** Function: percept_warning()
    ** Description: Calls room function that alerts the user if a UDLR room 
    ** contains an event
    ** Parameters: none
    ** Pre-Conditions: board is set up
    ** Post-Conditions: prints text to console if user is adjacent to a room
    ** containing an event
    *********************************************************************/
	void percept_warning();

	/*********************************************************************   
    ** Function: board_size()
    ** Description: prompts the user for l,w and debug mode
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: w, l and debug mode are assigned in program
    *********************************************************************/
	void board_size();

    /*Getter for length*/
	int get_length();

    /*Getter for width*/
	int	get_width();

    /*Getter for debug mode*/
	bool get_debug();



};
#endif