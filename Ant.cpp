/********************
** Author: Kelvin Lu
** Date: 09/27/2017
** Description: This is the class implementation file for the Ant class.
********************/

#include "Ant.hpp"

//Constructor
Ant::Ant(int rows, int cols, int x, int y)
{
	rowNum = x;
	colNum = y;
	antBoard = new Board(rows, cols);
	antBoard->setAnt(rowNum, colNum);
}

//Perform one movement for the ant and display the updated board.
void Ant::move()
{
	//Check if the ant is on a white space or black space
	if (antBoard->getColor() == WHITE)
	{
		//If white, rotate the ant to the right by 90 degrees
		switch (orientation)
		{
			case NORTH	:	
				orientation = EAST;
				break;
			case EAST	:	
				orientation = SOUTH;
				break;
			case SOUTH	:	
				orientation = WEST;
				break;
			case WEST	:	
				orientation = NORTH;

		}

		//Set the tile to black
		antBoard->setBlack(rowNum, colNum);
	} else
	{
		//If black, rotate the ant to the left by 90 degrees
		switch (orientation)
		{
			case NORTH	:	
				orientation = WEST;
				break;
			case WEST	:	
				orientation = SOUTH;
				break;
			case SOUTH	:	
				orientation = EAST;
				break;
			case EAST	:	
				orientation = NORTH;

		}

		//Set the tile to black
		antBoard->setWhite(rowNum, colNum);
	}

	//Move the ant one space forward. If ant will hit a border, have the ant wrap around and appear on the opposite side of the board
	switch (orientation)
	{
		case NORTH: 
			//If ant is located on the top row, wrap the ant to the bottom row in the same column
			if (rowNum == 1)
			{
				rowNum = antBoard->getRows();
			} else
			{
				rowNum--;
			}
			break;

			//If ant is located on the rightmost column, wrap the ant to the leftmost column in the same row
		case EAST:	
			if (colNum == antBoard->getCols())
			{
				colNum = 1;
			} else
			{
				colNum++;
			}
			break;

		case SOUTH:	
			//If ant is located on the bottom row, wrap the ant to the top row in the same column
			if (rowNum == antBoard->getRows())
			{
				rowNum = 1;
			}
			else
			{
				rowNum++;
			}
			break;

		case WEST:	
			//If ant is located on the leftmost column, wrap the ant to the rightmost column in the same row
			if (colNum == 1)
			{
				colNum = antBoard->getCols();
			}
			else
			{
				colNum--;
			}
	}

	//Mark the new tile that the ant is located on with the ant symbol
	antBoard->setAnt(rowNum, colNum);
	
	//Display the board
	antBoard->display();
}

//Calls the board method to display the board
void Ant::display()
{
	antBoard->display();
}

//Deallocates memory used to create the board
void Ant::deallocate()
{
	antBoard->erase();
	delete antBoard;
	antBoard = nullptr;
}
