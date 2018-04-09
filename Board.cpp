/********************
** Author: Kelvin Lu
** Date: 09/27/2017
** Description: This is the class specification file for the Board class.
********************/

#include "Board.hpp"
#include <iostream>



Board::Board(int r, int c)
{
	rows = r;
	cols = c;

	//Dynamically create a two-dimensional array
	board = new Color*[rows + 2];
	for (int i = 0; i < rows + 2; i++)
	{
		board[i] = new Color[cols + 2];
	}

	//First and last rows represent the top and bottom boundaries of the board
	for (int j = 0; j < cols + 2; j++)
	{
		setHorizontalBorder(0,j);
		setHorizontalBorder(rows + 1, j);
	}

	//First and last columns represent the left and right boundaries of the board
	for (int i = 1; i < rows + 1; i++)
	{
		setVerticalBorder(i, 0);
		setVerticalBorder(i, cols + 1);
	}

	//Fill the board with white spaces
	for (int i = 1; i < rows + 1; i++)
	{
		for (int j = 1; j < cols + 1; j++)
		{
			setWhite(i, j);
		}
	}
}

void Board::display()
{
	//Print board, including borders
	for (int i = 0; i < rows + 2; i++)
	{
		for (int j = 0; j < cols + 2; j++)
		{
			std::cout << static_cast<char>(board[i][j]);
		}
		std::cout << std::endl;
	}
}

void Board::setHorizontalBorder(int x, int y)
{
	board[x][y] = HORIZONTAL;
}

void Board::setVerticalBorder(int x, int y)
{
	board[x][y] = VERTICAL;
}

void Board::setWhite(int x, int y)
{
	board[x][y] = WHITE;
}

void Board::setBlack(int x, int y)
{
	board[x][y] = BLACK;
}

void Board::setAnt(int x, int y)
{
	color = board[x][y];
	board[x][y] = ANT;
}

int Board::getRows()
{
	return rows;
}

int Board::getCols()
{
	return cols;
}

Color Board::getColor()
{
	return color;
}

void Board::erase()
{
	//Deallocate memory used for board
	for (int i = 0; i < rows + 2; i++)
	{
		delete[] board[i];
	}
	delete[] board;

	//Set pointer to null
	board = nullptr;
}
