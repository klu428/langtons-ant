/********************
** Author: Kelvin Lu
** Date: 09/27/2017
** Description: This is the class specification file for the Board class.
********************/

#ifndef BOARD_HPP
#define BOARD_HPP

//Enumerator for board colors/symbols
enum Color { WHITE = ' ', BLACK = '#', ANT = '*', HORIZONTAL = '=', VERTICAL = '|' };

class Board
{
private:
	Color** board;
	int rows;
	int cols;
	Color color;

public:
	//Constructor to create the board
	Board(int r, int c);

	//Set horizontal borders
	void setHorizontalBorder(int x, int y);

	//Set vertical borders
	void setVerticalBorder(int x, int y);

	//Change the color to white at the coordinates denoted by x row and y column
	void setWhite(int x, int y);

	//Change the color to black at the coordinates denoted by x row and y column
	void setBlack(int x, int y);

	//Get the number of rows
	int getRows();

	//Get the number of columns
	int getCols();

	//Get the color of the tile the ant is located on
	Color getColor();

	//Move the ant to coordinates denoted by x row and y column
	void setAnt(int x, int y);

	//Print the board
	void display();

	//Erase board
	void erase();



};
#endif