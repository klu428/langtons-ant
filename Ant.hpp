/********************
** Author: Kelvin Lu
** Date: 09/27/2017
** Description: This is the class specification file for the Ant class.
********************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

//enumerator for orientation
enum Orientation {NORTH, SOUTH, EAST, WEST};

class Ant
{
private:
	Board *antBoard;
	int rowNum;
	int colNum;
	Orientation orientation = SOUTH;
public:
	//Constructor
	Ant(int rows, int cols, int x, int y);

	//Make one move
	void move();

	//Display Board
	void display();

	//Deallocate Board
	void deallocate();

};
#endif