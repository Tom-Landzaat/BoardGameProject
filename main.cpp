/****************************************************** 
** Program: main.cpp 
** Author: Thomas Landzaat
** Date: 11/27/2023 
** Description: Calls all game functions in the correct order
** to ensure playability of game.  
** Input: Dimensions of the board as well as debug mode 
** Output: Runs the whole game from prompting user input to displaying the grid on the screen.
******************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid = 6, len = 5;
	bool debug = true; //default to true for now to skip user input
	
	Game g;

	//get two inputs: size of the cave(wid and len)
	g.board_size();
	wid = g.get_width();
	len = g.get_length();
	debug = g.get_debug();


	//get the 3rd input --> debug mode or not


	//Play game
	g.play_game(wid, len, debug);


	return 0;
}